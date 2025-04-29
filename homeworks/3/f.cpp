#include <iostream>
#include <vector>
using namespace std;

const int MAXN = 1001;
const int BLOCK_SIZE = 64;

struct Fenwick2D {
    vector<vector<int>> tree;
    int n, m;

    Fenwick2D(int n, int m) : n(n), m(m) {
        tree.assign(n + 1, vector<int>(m + 1, 0));
    }

    void update(int x, int y, int delta) {
        for (int i = x; i <= n; i += i & -i) {
            for (int j = y; j <= m; j += j & -j) {
                tree[i][j] += delta;
            }
        }
    }

    int query(int x, int y) {
        int sum = 0;
        for (int i = x; i > 0; i -= i & -i) {
            for (int j = y; j > 0; j -= j & -j) {
                sum += tree[i][j];
            }
        }
        return sum;
    }

    int query(int x1, int y1, int x2, int y2) {
        return query(x2, y2) - query(x1 - 1, y2) - query(x2, y1 - 1) + query(x1 - 1, y1 - 1);
    }
};

int main() {
    int N, K;
    cin >> N >> K;

    Fenwick2D xy(N, N), xz(N, N), yz(N, N);

    for (int i = 0; i < K; ++i) {
        int x, y, z;
        cin >> x >> y >> z;
        xy.update(x, y, 1);
        xz.update(x, z, 1);
        yz.update(y, z, 1);
    }

    for (int x_block = 1; x_block <= N; x_block += BLOCK_SIZE) {
        for (int y_block = 1; y_block <= N; y_block += BLOCK_SIZE) {
            for (int z_block = 1; z_block <= N; z_block += BLOCK_SIZE) {
                bool block_covered = true;

                for (int x = x_block; x < x_block + BLOCK_SIZE && x <= N; ++x) {
                    for (int y = y_block; y < y_block + BLOCK_SIZE && y <= N; ++y) {
                        if (xy.query(x, y, x, y) == 0) {
                            for (int z = z_block; z < z_block + BLOCK_SIZE && z <= N; ++z) {
                                if (xz.query(x, z, x, z) == 0 && yz.query(y, z, y, z) == 0) {
                                    cout << "NO\n" << x << " " << y << " " << z << "\n";
                                    return 0;
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    cout << "YES\n";
    return 0;
}
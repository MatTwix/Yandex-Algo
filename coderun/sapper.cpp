#include <iostream>
#include <vector>

using namespace std;

int countBombsAround (const vector<vector<char>>& field, int x, int y) {
    int count = 0;

    for (int i = x - 1; i <= x + 1; ++i) {
        for (int j = y - 1; j <= y + 1; ++j) {
            if (i < 0 || i >= field.size() || j < 0 || j >= field[0].size()) {
                continue;
            }
            if (field[i][j] == '*') {
                count++;
            }
        }
    }

    return count;
}

int main (void) {
    int N, M, K;
    cin >> N >> M >> K;

    vector<vector<char>> field (N, vector<char>(M, '0'));

    for (int i = 0; i < K; ++i) {
        int x, y;
        cin >> x >> y;

        field[x - 1][y - 1] = '*';
    }

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            if (field[i][j] != '*') {
                field[i][j] = countBombsAround(field, i, j) + '0';
            }
        }
    }

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            cout << field[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
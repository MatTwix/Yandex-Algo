#include <iostream>
#include <vector>

using namespace std;

int find(int x, vector<int>& parents) {
    if (parents[x] != x) {
        parents[x] = find(parents[x], parents);
    }
    return parents[x];
}

bool isUnited(int x, int y, vector<int>& parents, vector<int>& rangs) {
    int rtX = find(x, parents);
    int rtY = find(y, parents);

    if (rtX != rtY) {
        if (rangs[rtX] < rangs[rtY]) {
            parents[rtX] = rtY;
        } else if (rangs[rtX] > rangs[rtY]) {
            parents[rtY] = rtX;
        } else {
            parents[rtY] = rtX;
            rangs[rtX]++;
        }
        return true;
    }
    return false;
}

int main() {
    int N, K;
    cin >> N >> K;

    vector<int> parents(N), rangs(N, 0);

    for (int i = 0; i < N; ++i) {
        parents[i] = i;
    }

    int components = N;

    for (int i = 0; i < K; ++i) {
        int x, y;
        cin >> x >> y;
        x--;
        y--;

        if (isUnited(x, y, parents, rangs)) {
            components--;
        }

        if (components == 1) {
            cout << i + 1 << endl;
            break;
        }
    }

    return 0;
}
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main (void) {
    int N, M;
    cin >> N >> M;

    vector<int> weights(N);
    for (auto i = 0; i < N; i++) {
        cin >> weights[i];
    }

    vector<int> results(M + 1, -1);
    results[0] = 0;

    for (auto i = 0; i < N; i++) {
        for (auto j = M; j >= 0; j--) {
            if (results[j] != -1 && j + weights[i] <= M) {
                results[j + weights[i]] = 1;
            }
        }
    }

    for (auto i = M; i >= 0; i--) {
        if (results[i] == 1) {
            cout << i << endl;
            return 0;
        }
    }

    cout << 0;
    return 0;
}
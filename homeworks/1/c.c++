#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

int main(void) {
    long long M;
    long long currPrice;
    cin >> M;
    
    vector<int> capacities(31);
    for (auto i = 0; i < 31; i++) cin >> capacities[i];

    vector<int> results(M + 2, -1);
    results[0] = 0;

    bool used = false;

    for (auto i = 0; i < 31; i++) {
        if (1LL << i > capacities[i] && used) continue;
        used = true;

        for (auto j = 0; j <= M; j++) {
            if (results[j] != -1) {
                currPrice = 1LL << i;
                for (auto currAmount = j; currAmount < M; currAmount += capacities[i]) {
                    if (currAmount + capacities[i] > M) {
                        if (results[M + 1] > currPrice + results[j] || results[M + 1] == -1) {
                            results[M + 1] = currPrice + results[j];
                        }
                    } else {
                        if (results[currAmount + capacities[i]] > currPrice + results[j] || results[currAmount + capacities[i]] == -1) {
                            results[currAmount + capacities[i]] = currPrice + results[j];
                        }
                    }
                    currPrice += 1LL << i;
                }
            }
        }
    }

    int ans;

    if (results[M] != -1 && results[M + 1] != -1) {
        ans = min(results[M], results[M + 1]);
    } else if (results[M] == -1) {
        ans = results[M + 1];
    } else {
        ans = results[M];
    }

    cout << ans << endl;

    return 0;
}
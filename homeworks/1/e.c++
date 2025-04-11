#include <iostream>
#include <vector>

using namespace std;

int main (void) {
    int N, M;
    int maxPrice = 0;
    cin >> N >> M;

    vector<int> weights(N);
    for (auto i = 0; i < N; i++) {
        cin >> weights[i];
    }

    vector<int> prices(N);
    for (auto i = 0; i < N; i++) {
        cin >> prices[i];
    }

    vector<int> results(M + 1, -1);
    results[0] = 0;

    for (auto i = 0; i < N; i++) {
        for (auto j = M; j >= 0; j--) {
            if (results[j] != -1 && j + weights[i] <= M) {
                if (results[j + weights[i]] < results[j] + prices[i]) {
                    results[j + weights[i]] = results[j] + prices[i];
                }
            }
        }
    }

    for (auto i = M; i >= 0; i--) {
        if (results[i] > maxPrice) {
            maxPrice = results[i];
        }   
    }

    cout << maxPrice << endl;
    return 0;
}
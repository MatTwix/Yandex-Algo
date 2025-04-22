#include <iostream>
#include <vector>

using namespace std;

int main (void) {
    int N;
    cin >> N;

    vector<int> prices (N);
    for (int i = 0; i < N; ++i) cin >> prices[i];

    long long res = 0;
    vector<int> pricesCnt (201);

    for (auto i = N - 1; i >= 0; --i) {
        for (int j = prices[i] + 1; j <= 200; ++j) {
            res += pricesCnt[j];
        }

        pricesCnt[prices[i]]++;
    }

    cout << res;

    return 0;
}
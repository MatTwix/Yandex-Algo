#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main (void) {
    int N, M, maxElId;
    int maxPrice = -1;
    
    cin >> N >> M;

    vector<int> weights(N);
    for (auto i = 0; i < N; i++) cin >> weights[i];

    vector<int> prices(N); 
    for (auto i = 0; i < N; i++) cin >> prices[i];

    // first - id
    // second - price
    vector<vector<pair<int, int>>> results(N + 1, vector<pair<int, int>>(M + 1, {-1, -1}));
    results[0][0] = {0, 0};

    for (auto i = 0; i < N; i++) {
        if (i > 0) {
            results[i] = results[i - 1];
        }

        for (auto j = M; j >= 0; j--) {
            if (results[i][j].first != -1 && j + weights[i] <= M) {
                if (results[i][j + weights[i]].second < prices[i] + results[i][j].second) {
                    results[i][j + weights[i]] = {i, prices[i] + results[i][j].second};
                }
            }
        }
    }

    vector<int> ans;

    int maxWeitght = 0;
    for (int j = 0; j <= M; j++) {
        if (results[N - 1][j].second > maxPrice) {
            maxPrice = results[N - 1][j].second;
            maxWeitght = j;
        }
    }
    
    int i = N - 1;
    int currWeight = maxWeitght;
    
    while (currWeight > 0 && i >= 0) {
        int maxIdx = results[i][currWeight].first;
        int cost = results[i][currWeight].second;

        if (maxIdx == -1) break;
    
        ans.push_back(maxIdx + 1);
        currWeight -= weights[maxIdx];
        maxPrice -= prices[maxIdx];
    
        i = maxIdx - 1;
    }

    sort(ans.begin(), ans.end());

    for (auto idx: ans) {
        cout << idx << endl;
    }

    return 0;
}
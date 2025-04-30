#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    dp[1][1] = 1;

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (i - 2 >= 1 && j - 1 >= 1) {
                dp[i][j] += dp[i - 2][j - 1];
            }
            if (i - 1 >= 1 && j - 2 >= 1) {
                dp[i][j] += dp[i - 1][j - 2];
            }
        }
    }

    cout << dp[n][m] << endl;

    return 0;
}
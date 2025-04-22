#include <iostream>
#include <vector>

using namespace std;

int main (void) {
    int N;
    cin >> N;

    vector<int> nums (N);
    for (auto i = 0; i < N; ++i) cin >> nums[i];

    int mxLen = 0;
    vector<vector<bool>> mtrx (N, vector<bool>(N, false));

    for (int i = 0; i < N; ++i) mtrx[i][i] = true;

    for (int i = 0; i < N - 1; ++i) {
        if (nums[i] == nums[i + 1]) {
            mtrx[i][i + 1] = true;
            mxLen = 2;
        }
    }
    
    for (int len = 3; len <= N; ++len) {
        for (int i = 0; i <= N - len; ++i) {
            int j = len + i - 1;
            if (nums[i] == nums[j] && mtrx[i + 1][j - 1]) {
                mtrx[i][j] = true;
                mxLen = max(mxLen, len);
            }
        }
    }
    
    cout << mxLen;

    return 0;
}
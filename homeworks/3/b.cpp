#include <iostream>
#include <vector>

using namespace std;

int main (void) {
    int N; 
    cin >> N;

    vector<int> res (N);
    vector<vector<int>> mtrx (N, vector<int> (N));

    for(int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> mtrx[i][j];
        }
    }

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            res[i] |= mtrx[i][j];
        }
    }

    for (auto el : res) {
        cout << el << " ";
    }

    return 0;
}
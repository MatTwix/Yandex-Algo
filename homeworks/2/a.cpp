#include <iostream>
#include <vector>

using namespace std;

typedef struct {
    int lChild, rChild, value, mx;
} Quadro;

int main (void) {
    int N, K;    
    cin >> N;

    int Npow = 1;
    for (auto i = 0; Npow < N; i++) Npow = 1 << i;

    vector<Quadro> tree (2 * Npow - 1, {-1, -1, -1, -1});

    for (auto i = 0; i < N; i++) {
        cin >> tree[Npow - 1 + i].value;
    }

    cin >> K;

    vector<pair<int, int>> segments (K);
    int bufL, bufR;
    for (auto i = 0; i < K; i++) {
        cin >> bufL >> bufR;
        segments[i].first = bufL - 1;
        segments[i].second = bufR - 1;
    }

    for (auto el : tree) cout << el.value << " ";
    cout << endl;

    return 0;
}
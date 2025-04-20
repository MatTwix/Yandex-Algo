#include <iostream>
#include <vector>

using namespace std;

typedef struct {
    int lChild, rChild, value, mxIdx, lBorder, rBorder;
} node;

void dfs (const vector<node> &tree, int idx, int &ansMx, int &ansIdx, const pair<int, int> &el) {
    // cout << idx << " " << tree[idx].value << " " << ansMx << endl;
    if (el.first > tree[idx].rBorder) {
        return;
    } else if (el.first <= tree[idx].lBorder && el.second >= tree[idx].rBorder) {
        if (tree[idx].value >= ansMx) {
            ansMx = tree[idx].value;
            ansIdx = tree[idx].mxIdx;
        }
    } else if (tree[idx].lBorder <= el.first && tree[idx].rBorder >= el.first || tree[idx].lBorder <= el.second && tree[idx].rBorder >= el.second) {
        dfs(tree, tree[idx].lChild, ansMx, ansIdx, el);
        dfs(tree, tree[idx].rChild, ansMx, ansIdx, el);
    }
}

int main (void) {
    int N, K;    
    cin >> N;

    int Npow = 1;
    for (auto i = 0; Npow < N; i++) Npow = 1 << i;

    vector<node> tree (2 * Npow - 1, {-1, -1, -1, 0, -1, -1});

    int buf;
    for (auto i = 0; i < Npow; i++) {
        buf = -1;
        if (i < N) cin >> buf;
        tree[Npow - 1 + i] = {-1, -1, buf, i, i, i};
    }

    cin >> K;

    vector<pair<int, int>> segments (K);
    int bufL, bufR;
    for (auto i = 0; i < K; i++) {
        cin >> bufL >> bufR;
        segments[i].first = bufL - 1;
        segments[i].second = bufR - 1;
    }

    int l, r, val, mxIdx;
    for (int i = Npow - 2; i >= 0; i--) {
        l = 2*i + 1;
        r = 2*i + 2;
        val = max(tree[l].value, tree[r].value);
        if (tree[l].value == tree[r].value) {
            mxIdx = tree[l].mxIdx;
        } else {
            mxIdx = (tree[l].value > tree[r].value) ? tree[l].mxIdx : tree[r].mxIdx;
        }
        
        tree[i] = {l, r, val, mxIdx, tree[l].lBorder, tree[r].rBorder};
    }

    // for (int i = 0; i < 2 * Npow - 1; i++) {
    //     if (log2(i + 1) == ceil(log2(i + 1))) {
    //         cout << endl;
    //     }
    //     cout << tree[i].mxIdx << ":" << tree[i].value << " ";
    // }

    int ansMx, ansIdx;

    for (auto el : segments) {
        ansMx = -1;
        ansIdx = -1;

        dfs(tree, 0, ansMx, ansIdx, el);

        cout << ansMx << " " << ansIdx + 1 << endl;
    }

    return 0;
}
#include <iostream>
#include <vector>

using namespace std;

typedef struct {
    int lChild, rChild, value, mxNum, lBorder, rBorder;
} node;

void dfs (vector<node> tree, int idx, int &ansMx, int &ansMxNum, pair<int, int> el) {
    // cout << idx << " " << tree[idx].value << " " << ansMx << endl;
    if (tree[idx].lChild != -1) {
        if (tree[idx].rBorder < el.first || tree[idx].lBorder > el.second) {
            return;
        } else if (tree[idx].lBorder >= el.first && tree[idx].rBorder <= el.second) {
            // cout << "i'm here ";
            if (ansMx < tree[idx].value) {
                ansMx = tree[idx].value;
                ansMxNum = tree[idx].mxNum;
            } else if (ansMx == tree[idx].value) {
                ansMxNum += tree[idx].mxNum;
            }
        } else {
            dfs(tree, tree[idx].lChild, ansMx, ansMxNum, el);
            dfs(tree, tree[idx].rChild, ansMx, ansMxNum, el);
        }
    }
}

int main (void) {
    int N, K;    
    cin >> N;

    int Npow = 1;
    for (auto i = 0; Npow < N; i++) Npow = 1 << i;

    vector<node> tree (2 * Npow - 1, {-1, -1, -1, 0, -1, -1});

    int buf;
    for (auto i = 0; i < N; i++) {
        cin >> buf;
        tree[Npow - 1 + i] = {-1, -1, buf, 1, i, i};
    }

    cin >> K;

    vector<pair<int, int>> segments (K);
    int bufL, bufR;
    for (auto i = 0; i < K; i++) {
        cin >> bufL >> bufR;
        segments[i].first = bufL - 1;
        segments[i].second = bufR - 1;
    }

    int l, r, val, mxNum;
    for (int i = Npow - 2; i >= 0; i--) {
        l = 2*i + 1;
        r = 2*i + 2;
        val = max(tree[l].value, tree[r].value);
        if (tree[l].value == tree[r].value) {
            mxNum = tree[l].mxNum + tree[r].mxNum;
        } else {
            mxNum = (tree[l].value > tree[r].value) ? tree[l].mxNum : tree[r].mxNum;
        }
        
        tree[i] = {l, r, val, mxNum, tree[l].lBorder, (tree[r].rBorder == -1) ? N : tree[r].rBorder};
    }

    // for (int i = 0; i < 2 * Npow - 1; i++) {
    //     if (log2(i + 1) == ceil(log2(i + 1))) {
    //         cout << endl;
    //     }
    //     cout << tree[i].lChild << ">" << tree[i].lBorder << ">" << tree[i].value << "<" << tree[i].rBorder << "<" << tree[i].rChild << " ";
    // }

    int ansMx, ansMxNum;

    for (auto el : segments) {
        ansMx = -1;
        ansMxNum = 0;

        dfs(tree, 0, ansMx, ansMxNum, el);

        cout << ansMx << " " << ansMxNum << endl;
    }

    return 0;
}
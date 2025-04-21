#include <iostream>
#include <vector>

using namespace std;

typedef struct {
    int lChild, rChild;
    int lBorder, rBorder;
    pair<int, int> promice;
    int value;
} node;

typedef struct {
    char reqType;
    int first, second;
} triple;

void updateTree(vector<node> &tree, int idx, const triple &el) {
    if (tree[idx].lBorder == el.first && tree[idx].rBorder == el.first) tree[idx].value = el.second;
    else if (tree[idx].lBorder <= el.first && el.first <= tree[idx].rBorder) {
        updateTree(tree, tree[idx].lChild, el);
        updateTree(tree, tree[idx].rChild, el);

        tree[idx].value = max(tree[tree[idx].lChild].value, tree[tree[idx].rChild].value);
    }
}

void dfs(vector<node> &tree, int idx, int &ansMx, const triple &el) {
    if (el.first > tree[idx].rBorder) return;
    else if (el.first <= tree[idx].lBorder && el.second >= tree[idx].rBorder) ansMx = max(ansMx, tree[idx].value);
    else if (tree[idx].lBorder <= el.first && tree[idx].rBorder >= el.first || tree[idx].lBorder <= el.second && tree[idx].rBorder >= el.second) {
        dfs(tree, tree[idx].lChild, ansMx, el);
        dfs(tree, tree[idx].rChild, ansMx, el);
    }
}

int main (void) {
    int N, M;
    cin >> N;

    int Npow = 1;
    for (auto i = 0; Npow < N; i++) Npow = 1 << i;

    vector<node> tree (2 * Npow - 1, {-1, -1, -1, -1, {-1, -1}, -1});

    int buf;
    for (auto i = 0; i < Npow; i++) {
        buf = -1;
        if (i < N) cin >> buf;
        tree[Npow - 1 + i] = {-1, -1, i, i, {-1, -1}, buf};
    }

    cin >> M;
    vector<triple> requests (M);
    char reqType;
    int bufFst, bufSnd;

    for (auto i = 0; i < M; i++) {
        cin >> reqType >> bufFst >> bufSnd;
        requests[i] = {reqType, bufFst, bufSnd};

        requests[i].first--;

        if (reqType == 's') {
            requests[i].second--;
        }
    }

    int l, r, val;

    for (int i = Npow - 2; i >= 0; i--) {
        l = 2*i + 1;
        r = 2*i + 2;
        val = max(tree[l].value, tree[r].value);

        tree[i] = {l, r, tree[l].lBorder, tree[r].rBorder, {-1, -1} , val};
    }

    // for (int i = 0; i < 2 * Npow - 1; i++) {
    //     if (log2(i + 1) == ceil(log2(i + 1))) {
    //         cout << endl;
    //     }
    //     cout << tree[i].value << " ";
    // }

    int ansMx;

    for (auto el : requests) {
        ansMx = -1;

        if (el.reqType == 's') {
            dfs(tree, 0, ansMx, el);
            cout << ansMx << " ";
        } else {
            updateTree(tree, 0, el);
        }
    }

    return 0;
}
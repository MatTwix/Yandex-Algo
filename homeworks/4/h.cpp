#include <iostream>
#include <vector>
#include <string>
#include <stack>

using namespace std;

class DSU {
public:
    vector<int> parent, rang;

    DSU(int n) {
        parent.resize(n + 1);
        rang.resize(n + 1, 0);
        for (int i = 1; i <= n; ++i) {
            parent[i] = i;
        }
    }

    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    void merge(int x, int y) {
        int rX = find(x);
        int rY = find(y);

        if (rX != rY) {
            if (rang[rX] < rang[rY]) {
                parent[rX] = rY;
            } else if (rang[rX] > rang[rY]) {
                parent[rY] = rX;
            } else {
                parent[rY] = rX;
                rang[rX]++;
            }
        }
    }
};

int main() {
    int n, m, k;
    cin >> n >> m >> k;

    vector<pair<int, int>> edges(m);
    vector<pair<string, pair<int, int>>> operations(k);

    for (int i = 0; i < m; ++i) {
        cin >> edges[i].first >> edges[i].second;
    }

    for (int i = 0; i < k; ++i) {
        string type;
        int u, v;
        cin >> type >> u >> v;
        operations[i] = {type, {u, v}};
    }

    DSU dsu(n);

    stack<string> results;

    for (int i = k - 1; i >= 0; --i) {
        string type = operations[i].first;
        int u = operations[i].second.first;
        int v = operations[i].second.second;

        if (type == "ask") {
            if (dsu.find(u) == dsu.find(v)) {
                results.push("YES");
            } else {
                results.push("NO");
            }
        } else if (type == "cut") {
            dsu.merge(u, v);
        }
    }

    while (!results.empty()) {
        cout << results.top() << endl;
        results.pop();
    }

    return 0;
}
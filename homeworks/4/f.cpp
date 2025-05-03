#include <iostream>
#include <vector>

using namespace std;

void dfs(int idx, vector<vector<int>>& graph, vector<bool>& visited) {
    visited[idx] = true;

    for (int u : graph[idx]) {
        if (!visited[u]) {
            dfs(u, graph, visited);
        }
    }
}

int main (void) {
    int N;
    cin >> N;

    vector<int> savers(N);

    for (int i = 0; i < N; ++i) {
        cin >> savers[i];
        --savers[i];
    }

    vector<vector<int>> graph(N);
    for (int i = 0; i < N; ++i) {
        graph[i].push_back(savers[i]);
        graph[savers[i]].push_back(i);
    }

    vector<bool> visited(N, false);
    int components = 0;

    for (int i = 0; i < N; ++i) {
        if (!visited[i]) {
            dfs(i, graph, visited);
            ++components;
        }
    }

    cout << components << endl;

    return 0;
}
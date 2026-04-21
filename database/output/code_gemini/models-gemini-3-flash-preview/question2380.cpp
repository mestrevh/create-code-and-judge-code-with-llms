/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>

using namespace std;

void dfs(int u, vector<vector<int>>& adj, vector<bool>& visited) {
    visited[u] = true;
    for (int i = (int)adj[u].size() - 1; i >= 0; --i) {
        int v = adj[u][i];
        if (!visited[v]) {
            dfs(v, adj, visited);
        }
    }
    cout << u << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;
    
    int start;
    if (!(cin >> start)) return 0;

    vector<vector<int>> adj(n);
    int u, v;
    while (cin >> u >> v) {
        if (u >= 0 && u < n) {
            adj[u].push_back(v);
        }
    }

    vector<bool> visited(n, false);
    if (start >= 0 && start < n) {
        dfs(start, adj, visited);
    }

    return 0;
}
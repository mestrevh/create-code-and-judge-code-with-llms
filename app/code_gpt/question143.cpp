/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

void dfs(int v, vector<vector<int>>& g, vector<bool>& visited) {
    visited[v] = true;
    for (int u : g[v]) {
        if (!visited[u]) {
            dfs(u, g, visited);
        }
    }
}

bool isStronglyConnected(int n, vector<vector<int>>& g) {
    vector<bool> visited(n + 1);
    dfs(1, g, visited);
    
    for (int i = 1; i <= n; ++i) {
        if (!visited[i]) return false;
    }
    
    vector<vector<int>> g_rev(n + 1);
    for (int v = 1; v <= n; ++v) {
        for (int u : g[v]) {
            g_rev[u].push_back(v);
        }
    }
    
    fill(visited.begin(), visited.end(), false);
    dfs(1, g_rev, visited);
    
    for (int i = 1; i <= n; ++i) {
        if (!visited[i]) return false;
    }
    
    return true;
}

int main() {
    int n, m;
    while (cin >> n >> m, n || m) {
        vector<vector<int>> g(n + 1);
        for (int i = 0; i < m; ++i) {
            int v, w, p;
            cin >> v >> w >> p;
            g[v].push_back(w);
            if (p == 2) g[w].push_back(v);
        }
        cout << (isStronglyConnected(n, g) ? 1 : 0) << endl;
    }
    return 0;
}

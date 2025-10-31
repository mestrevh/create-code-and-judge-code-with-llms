/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm>

int n, m;
std::vector<int> adj[26];
bool used[26][26];
int maxLength;

void dfs(int u, int currentLength) {
    maxLength = std::max(maxLength, currentLength);

    for (int v : adj[u]) {
        if (!used[u][v]) {
            used[u][v] = true;
            used[v][u] = true;

            dfs(v, currentLength + 1);

            used[u][v] = false;
            used[v][u] = false;
        }
    }
}

void solve() {
    for (int i = 0; i < n; ++i) {
        adj[i].clear();
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            used[i][j] = false;
        }
    }
    maxLength = 0;

    for (int i = 0; i < m; ++i) {
        int u, v;
        std::cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for (int i = 0; i < n; ++i) {
        dfs(i, 0);
    }

    std::cout << maxLength << std::endl;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    while (std::cin >> n >> m && (n != 0 || m != 0)) {
        solve();
    }

    return 0;
}

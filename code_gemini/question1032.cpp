/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>

void dfs(int u, const std::vector<int>& adj, std::vector<bool>& visited) {
    visited[u] = true;
    int v = adj[u];
    if (!visited[v]) {
        dfs(v, adj, visited);
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;

    std::vector<int> adj(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> adj[i];
    }

    std::vector<bool> visited(n, false);
    int count = 0;

    for (int i = 0; i < n; ++i) {
        if (!visited[i]) {
            count++;
            int current = i;
            while (!visited[current]) {
                visited[current] = true;
                current = adj[current];
            }
        }
    }

    std::cout << count << std::endl;

    return 0;
}

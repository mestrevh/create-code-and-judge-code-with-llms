/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>

bool hasCycleDFS(int u, int parent, const std::vector<std::vector<int>>& adj, std::vector<bool>& visited) {
    visited[u] = true;
    for (int v : adj[u]) {
        if (!visited[v]) {
            if (hasCycleDFS(v, u, adj, visited)) {
                return true;
            }
        } else if (v != parent) {
            return true;
        }
    }
    return false;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int N, M;
    int case_num = 1;
    while (std::cin >> N >> M) {
        std::vector<std::vector<int>> adj(N);
        for (int i = 0; i < M; ++i) {
            int u, v;
            std::cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        std::vector<bool> visited(N, false);
        bool cycle_found = false;
        for (int i = 0; i < N; ++i) {
            if (!visited[i]) {
                if (hasCycleDFS(i, -1, adj, visited)) {
                    cycle_found = true;
                    break;
                }
            }
        }
        std::cout << case_num++ << " " << (cycle_found ? 1 : 0) << std::endl;
    }

    return 0;
}

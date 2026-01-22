/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <numeric>

void dfs(int u, const std::vector<std::vector<int>>& graph, std::vector<bool>& visited) {
    visited[u] = true;
    for (int v : graph[u]) {
        if (!visited[v]) {
            dfs(v, graph, visited);
        }
    }
}

bool check_all_visited(int n, const std::vector<bool>& visited) {
    for (int i = 1; i <= n; ++i) {
        if (!visited[i]) {
            return false;
        }
    }
    return true;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int N, M;
    while (std::cin >> N >> M && (N != 0 || M != 0)) {
        std::vector<std::vector<int>> adj(N + 1);
        std::vector<std::vector<int>> rev_adj(N + 1);

        for (int i = 0; i < M; ++i) {
            int V, W, P;
            std::cin >> V >> W >> P;
            adj[V].push_back(W);
            rev_adj[W].push_back(V);
            if (P == 2) {
                adj[W].push_back(V);
                rev_adj[V].push_back(W);
            }
        }

        bool is_strongly_connected = true;

        std::vector<bool> visited(N + 1, false);
        dfs(1, adj, visited);
        if (!check_all_visited(N, visited)) {
            is_strongly_connected = false;
        }

        if (is_strongly_connected) {
            std::fill(visited.begin(), visited.end(), false);
            dfs(1, rev_adj, visited);
            if (!check_all_visited(N, visited)) {
                is_strongly_connected = false;
            }
        }

        if (is_strongly_connected) {
            std::cout << 1 << "\n";
        } else {
            std::cout << 0 << "\n";
        }
    }

    return 0;
}

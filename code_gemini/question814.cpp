/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <cstring>

void dfs(int u, const std::vector<int> adj[], bool visited[]) {
    visited[u] = true;
    for (int v : adj[u]) {
        if (!visited[v]) {
            dfs(v, adj, visited);
        }
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    int test_case = 1;
    while (std::cin >> n && n != 0) {
        std::vector<int> adj[7];
        int degree[7];
        bool visited[7];

        std::memset(degree, 0, sizeof(degree));
        std::memset(visited, 0, sizeof(visited));

        int start_node = -1;
        for (int i = 0; i < n; ++i) {
            int u, v;
            std::cin >> u >> v;
            degree[u]++;
            degree[v]++;
            adj[u].push_back(v);
            adj[v].push_back(u);
            if (start_node == -1) {
                start_node = u;
            }
        }

        std::cout << "Teste " << test_case++ << std::endl;

        int odd_degree_count = 0;
        for (int i = 0; i < 7; ++i) {
            if (degree[i] % 2 != 0) {
                odd_degree_count++;
            }
        }

        bool possible = true;
        if (odd_degree_count != 0 && odd_degree_count != 2) {
            possible = false;
        }

        if (possible && start_node != -1) {
            dfs(start_node, adj, visited);
            for (int i = 0; i < 7; ++i) {
                if (degree[i] > 0 && !visited[i]) {
                    possible = false;
                    break;
                }
            }
        }

        if (possible) {
            std::cout << "sim" << std::endl << std::endl;
        } else {
            std::cout << "nao" << std::endl << std::endl;
        }
    }

    return 0;
}

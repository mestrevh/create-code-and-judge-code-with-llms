/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <functional>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int num_vertices;
    std::cin >> num_vertices;

    int start_vertex;
    std::cin >> start_vertex;

    std::vector<std::vector<int>> adj(num_vertices);
    int u, v;
    while (std::cin >> u >> v) {
        adj[u].push_back(v);
    }

    for (int i = 0; i < num_vertices; ++i) {
        std::sort(adj[i].begin(), adj[i].end(), std::greater<int>());
    }

    std::vector<bool> visited(num_vertices, false);
    std::queue<int> q;

    if (start_vertex >= 0 && start_vertex < num_vertices) {
        visited[start_vertex] = true;
        q.push(start_vertex);
        std::cout << start_vertex << "\n";

        while (!q.empty()) {
            int current_node = q.front();
            q.pop();

            for (int neighbor : adj[current_node]) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    q.push(neighbor);
                    std::cout << neighbor << "\n";
                }
            }
        }
    }

    return 0;
}

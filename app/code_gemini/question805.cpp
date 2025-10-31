/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>

void bfs(int start_node, int V, const std::vector<std::vector<int>>& adj, std::vector<int>& dist, std::vector<int>& pred) {
    dist.assign(V, -1);
    pred.assign(V, -1);
    std::queue<int> q;

    dist[start_node] = 0;
    q.push(start_node);

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        std::cout << "Iniciando busca em largura a partir de " << u << std::endl;

        for (int v : adj[u]) {
            if (dist[v] == -1) {
                dist[v] = dist[u] + 1;
                pred[v] = u;
                q.push(v);
            }
        }
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int V, A, T;
    std::cin >> V >> A >> T;

    std::vector<std::vector<int>> adj(V);
    for (int i = 0; i < A; ++i) {
        int u, v;
        std::cin >> u >> v;
        adj[u].push_back(v);
    }

    for (int i = 0; i < V; ++i) {
        std::sort(adj[i].begin(), adj[i].end());
    }

    for (int t = 1; t <= T; ++t) {
        int source, dest;
        std::cin >> source >> dest;

        std::cout << "--------" << std::endl << std::endl;
        std::cout << "Caso de Teste #" << t << " - BFS(" << source << ")" << std::endl << std::endl;

        std::vector<int> dist, pred;
        bfs(source, V, adj, dist, pred);

        std::cout << std::endl;
        for (int i = 0; i < V; ++i) {
            std::cout << i << " | ";
            if (dist[i] == -1) {
                std::cout << "- | -";
            } else {
                std::cout << dist[i] << " | ";
                if (pred[i] == -1) {
                    std::cout << "-";
                } else {
                    std::cout << pred[i];
                }
            }
            std::cout << std::endl;
        }
        std::cout << std::endl;

        if (dist[dest] == -1) {
            std::cout << "Sem caminho entre " << source << " e " << dest << std::endl;
        } else {
            std::vector<int> path;
            for (int at = dest; at != -1; at = pred[at]) {
                path.push_back(at);
            }
            std::reverse(path.begin(), path.end());

            std::cout << "Caminho entre " << source << " e " << dest << ": ";
            for (size_t i = 0; i < path.size(); ++i) {
                std::cout << path[i] << (i == path.size() - 1 ? "" : " => ");
            }
            std::cout << std::endl;
        }
    }

    std::cout << "--------" << std::endl;

    return 0;
}

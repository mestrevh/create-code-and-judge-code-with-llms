/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <functional>

const int INF = 1e9;

std::vector<int> dijkstra(int start, int N, const std::vector<std::vector<std::pair<int, int>>>& adj) {
    std::vector<int> dist(N, INF);
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> pq;

    dist[start] = 0;
    pq.push({0, start});

    while (!pq.empty()) {
        int d = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        if (d > dist[u]) {
            continue;
        }

        for (const auto& edge : adj[u]) {
            int v = edge.first;
            int weight = edge.second;
            if (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v});
            }
        }
    }
    return dist;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int N, M;
    int case_num = 0;
    while (std::cin >> N >> M) {
        std::vector<std::vector<std::pair<int, int>>> adj(N);
        std::vector<int> degree(N, 0);

        for (int i = 0; i < M; ++i) {
            int u, v, d;
            std::cin >> u >> v >> d;
            adj[u].push_back({v, d});
            adj[v].push_back({u, d});
            degree[u]++;
            degree[v]++;
        }

        std::vector<std::vector<int>> lines;
        std::vector<bool> visited(N, false);

        for (int i = 0; i < N; ++i) {
            if (!visited[i] && !adj[i].empty()) {
                std::vector<int> current_line_terminals;
                std::queue<int> q;

                q.push(i);
                visited[i] = true;

                while (!q.empty()) {
                    int u = q.front();
                    q.pop();

                    if (degree[u] != 2) {
                        current_line_terminals.push_back(u);
                    }

                    for (auto& edge : adj[u]) {
                        int v = edge.first;
                        if (!visited[v]) {
                            visited[v] = true;
                            q.push(v);
                        }
                    }
                }
                
                if (!current_line_terminals.empty()) {
                    std::sort(current_line_terminals.begin(), current_line_terminals.end());
                    lines.push_back(current_line_terminals);
                }
            }
        }
        
        std::sort(lines.begin(), lines.end(), [](const std::vector<int>& a, const std::vector<int>& b) {
            return a[0] < b[0];
        });

        std::cout << "caso " << case_num++ << std::endl;

        for (const auto& line_terminals : lines) {
            int start_node = line_terminals[0];
            std::vector<int> dists = dijkstra(start_node, N, adj);

            for (size_t i = 0; i < line_terminals.size(); ++i) {
                std::cout << dists[line_terminals[i]] << (i == line_terminals.size() - 1 ? "" : " ");
            }
            std::cout << std::endl;
        }
    }
    return 0;
}

/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <climits>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int N, E, S, M;
    std::cin >> N >> E >> S >> M;

    std::vector<std::vector<std::pair<int, int>>> adj(N);
    for (int i = 0; i < M; ++i) {
        int u, v, t;
        std::cin >> u >> v >> t;
        adj[u].push_back({v, t});
    }

    std::vector<std::vector<int>> dist(N, std::vector<int>(3, -1));
    std::queue<std::pair<int, int>> q;

    dist[E][0] = 0;
    q.push({0, E});

    while (!q.empty()) {
        std::pair<int, int> current = q.front();
        q.pop();
        int time = current.first;
        int u = current.second;
        int time_mod_3 = time % 3;
        
        for (const auto& edge : adj[u]) {
            int v = edge.first;
            int type = edge.second;

            bool is_green = false;
            if (type == 1) {
                if (time_mod_3 == 0) {
                    is_green = true;
                }
            } else {
                if (time_mod_3 != 0) {
                    is_green = true;
                }
            }

            if (is_green) {
                int new_time = time + 1;
                int new_time_mod_3 = new_time % 3;

                if (dist[v][new_time_mod_3] == -1) {
                    dist[v][new_time_mod_3] = new_time;
                    q.push({new_time, v});
                }
            }
        }
    }

    int result = INT_MAX;
    if (dist[S][0] != -1) {
        result = std::min(result, dist[S][0]);
    }
    if (dist[S][1] != -1) {
        result = std::min(result, dist[S][1]);
    }
    if (dist[S][2] != -1) {
        result = std::min(result, dist[S][2]);
    }
    
    if (result == INT_MAX) {
        std::cout << "*" << std::endl;
    } else {
        std::cout << result << std::endl;
    }

    return 0;
}

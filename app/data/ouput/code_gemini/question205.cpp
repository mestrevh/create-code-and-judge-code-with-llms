/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <queue>
#include <utility>

std::vector<int> adj[1000001];

std::pair<int, int> bfs(int start_node, int n) {
    std::vector<int> dist(n + 1, -1);
    std::queue<int> q;

    dist[start_node] = 0;
    q.push(start_node);

    int farthest_node = start_node;
    int max_dist = 0;

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        if (dist[u] > max_dist) {
            max_dist = dist[u];
            farthest_node = u;
        }

        for (int v : adj[u]) {
            if (dist[v] == -1) {
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }
    return {farthest_node, max_dist};
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;

    if (n <= 1) {
        std::cout << 0 << std::endl;
        return 0;
    }

    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        std::cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    std::pair<int, int> first_bfs_result = bfs(1, n);
    int endpoint = first_bfs_result.first;

    std::pair<int, int> second_bfs_result = bfs(endpoint, n);
    int diameter = second_bfs_result.second;

    std::cout << diameter << std::endl;

    return 0;
}

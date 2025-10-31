/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <utility>

int n_nodes;
std::vector<std::vector<int>> adj;
std::vector<bool> visited;
int visited_count;

void dfs(int u) {
    visited[u] = true;
    visited_count++;
    for (int v : adj[u]) {
        if (!visited[v]) {
            dfs(v);
        }
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int d;
    std::cin >> n_nodes >> d;

    long long d_sq = (long long)d * d;

    std::vector<std::pair<int, int>> coords(n_nodes);
    for (int i = 0; i < n_nodes; ++i) {
        std::cin >> coords[i].first >> coords[i].second;
    }

    adj.resize(n_nodes);
    for (int i = 0; i < n_nodes; ++i) {
        for (int j = i + 1; j < n_nodes; ++j) {
            long long dx = coords[i].first - coords[j].first;
            long long dy = coords[i].second - coords[j].second;
            if (dx * dx + dy * dy <= d_sq) {
                adj[i].push_back(j);
                adj[j].push_back(i);
            }
        }
    }

    visited.assign(n_nodes, false);
    visited_count = 0;
    
    dfs(0);

    if (visited_count == n_nodes) {
        std::cout << 'S' << '\n';
    } else {
        std::cout << 'N' << '\n';
    }

    return 0;
}

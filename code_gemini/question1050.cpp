/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <queue>
#include <utility>
#include <algorithm>

std::vector<int> parent;
std::vector<std::map<int, int>> adj;
int num_vertices;

int find_set(int v) {
    if (v == parent[v]) {
        return v;
    }
    return parent[v] = find_set(parent[v]);
}

void unite_op(int u, int v) {
    int root_u = find_set(u);
    int root_v = find_set(v);

    if (root_u == root_v) {
        return;
    }

    if (adj[root_u].size() < adj[root_v].size()) {
        std::swap(root_u, root_v);
    }

    parent[root_v] = root_u;
    num_vertices--;

    if (adj[root_u].count(root_v)) {
        adj[root_u][root_v]--;
        if (adj[root_u][root_v] == 0) {
            adj[root_u].erase(root_v);
        }
    }
    if (adj[root_v].count(root_u)) {
        adj[root_v][root_u]--;
        if (adj[root_v][root_u] == 0) {
            adj[root_v].erase(root_u);
        }
    }

    for (auto const& [neighbor, count] : adj[root_v]) {
        adj[root_u][neighbor] += count;
        adj[neighbor][root_u] += count;
        adj[neighbor].erase(root_v);
    }
    adj[root_v].clear();
}

int bfs(int start_node, int end_node, int n) {
    if (start_node == end_node) {
        return 0;
    }

    std::queue<std::pair<int, int>> q;
    q.push({start_node, 0});

    std::vector<int> dist(n + 1, -1);
    dist[start_node] = 0;

    while (!q.empty()) {
        auto curr_pair = q.front();
        q.pop();
        int u = curr_pair.first;
        int d = curr_pair.second;

        if (u == end_node) {
            return d;
        }

        if (u < adj.size()) {
            for (auto const& [v, count] : adj[u]) {
                if (dist[v] == -1) {
                    dist[v] = d + 1;
                    q.push({v, d + 1});
                }
            }
        }
    }
    return -1;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n, m;
    std::cin >> n >> m;

    parent.resize(n);
    adj.resize(n);
    num_vertices = n;

    for (int i = 0; i < n; ++i) {
        parent[i] = i;
    }

    for (int i = 0; i < m; ++i) {
        int u, v;
        std::cin >> u >> v;
        if (u != v) {
            adj[u][v]++;
            adj[v][u]++;
        }
    }

    int o;
    std::cin >> o;

    while (o--) {
        char type;
        int u, v;
        std::cin >> type >> u >> v;
        if (type == 'c') {
            unite_op(u, v);
            std::cout << num_vertices << "\n";
        } else {
            int root_u = find_set(u);
            int root_v = find_set(v);
            std::cout << bfs(root_u, root_v, n) << "\n";
        }
    }

    return 0;
}

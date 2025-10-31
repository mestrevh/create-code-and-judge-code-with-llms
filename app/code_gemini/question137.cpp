/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

int N, M;

void dfs_connectivity(int u, const std::vector<std::vector<int>>& adj, std::vector<bool>& visited) {
    visited[u] = true;
    for (int v : adj[u]) {
        if (!visited[v]) {
            dfs_connectivity(v, adj, visited);
        }
    }
}

int count_visited(int n, const std::vector<bool>& visited) {
    int count = 0;
    for (int i = 1; i <= n; ++i) {
        if (visited[i]) {
            count++;
        }
    }
    return count;
}

std::vector<int> tin, low;
int timer;
bool oneway_bridge_found;

void find_bridges(int u, int p, const std::vector<std::vector<int>>& adj, const std::set<std::pair<int, int>>& oneway_edges) {
    if (oneway_bridge_found) return;
    tin[u] = low[u] = timer++;
    
    for (int v : adj[u]) {
        if (v == p) continue;
        if (tin[v] != -1) {
            low[u] = std::min(low[u], tin[v]);
        } else {
            find_bridges(v, u, adj, oneway_edges);
            if (oneway_bridge_found) return;
            low[u] = std::min(low[u], low[v]);
            if (low[v] > tin[u]) {
                std::pair<int, int> bridge = {std::min(u, v), std::max(u, v)};
                if (oneway_edges.count(bridge)) {
                    oneway_bridge_found = true;
                    return;
                }
            }
        }
    }
}

void solve() {
    int ru, rv, rt;
    std::cin >> ru >> rv >> rt;

    std::set<std::pair<int, int>> oneway_undir_edges;
    std::vector<std::vector<int>> adj_undir(N + 1);
    std::vector<std::vector<int>> adj_dir(N + 1);
    std::vector<std::vector<int>> adj_rev(N + 1);

    for (int i = 0; i < M - 1; ++i) {
        int u, v, t;
        std::cin >> u >> v >> t;
        
        adj_undir[u].push_back(v);
        adj_undir[v].push_back(u);

        if (t == 1) {
            adj_dir[u].push_back(v);
            adj_rev[v].push_back(u);
            oneway_undir_edges.insert({std::min(u, v), std::max(u, v)});
        } else {
            adj_dir[u].push_back(v);
            adj_dir[v].push_back(u);
            adj_rev[u].push_back(v);
            adj_rev[v].push_back(u);
        }
    }

    if (N > 0) {
        std::vector<bool> visited(N + 1, false);
        dfs_connectivity(1, adj_undir, visited);
        if (count_visited(N, visited) < N) {
            std::cout << "*\n";
            return;
        }

        std::fill(visited.begin(), visited.end(), false);
        dfs_connectivity(1, adj_dir, visited);
        bool forward_ok = (count_visited(N, visited) == N);

        std::fill(visited.begin(), visited.end(), false);
        dfs_connectivity(1, adj_rev, visited);
        bool backward_ok = (count_visited(N, visited) == N);

        if (forward_ok && backward_ok) {
            std::cout << "-\n";
            return;
        }
    } else {
         std::cout << "*\n";
         return;
    }


    tin.assign(N + 1, -1);
    low.assign(N + 1, -1);
    timer = 0;
    oneway_bridge_found = false;
    
    find_bridges(1, -1, adj_undir, oneway_undir_edges);

    if (oneway_bridge_found) {
        std::cout << "2\n";
    } else {
        std::cout << "1\n";
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    while (std::cin >> N >> M && (N != -1 || M != -1)) {
        solve();
    }
    return 0;
}

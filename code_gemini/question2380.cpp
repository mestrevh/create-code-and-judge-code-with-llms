/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

std::vector<std::vector<int>> adj;
std::vector<bool> visited;
std::vector<int> result;

void dfs(int u) {
    visited[u] = true;
    for (int v : adj[u]) {
        if (!visited[v]) {
            dfs(v);
        }
    }
    result.push_back(u);
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;

    int start_node;
    std::cin >> start_node;

    adj.resize(n);
    visited.assign(n, false);

    int u, v;
    while (std::cin >> u >> v) {
        adj[u].push_back(v);
    }

    for (int i = 0; i < n; ++i) {
        std::sort(adj[i].rbegin(), adj[i].rend());
    }

    dfs(start_node);
    
    // Check for other components, although the problem implies starting from a single point
    // This loop ensures all nodes are visited even if the graph is not connected
    // or if the starting node cannot reach all other nodes.
    for (int i = 0; i < n; ++i) {
        if (!visited[i]) {
            dfs(i);
        }
    }

    for (int node : result) {
        std::cout << node << "\n";
    }

    return 0;
}

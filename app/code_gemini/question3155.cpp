/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

void traverse(int start_node, const std::vector<std::vector<int>>& adj, std::vector<bool>& visited) {
    std::vector<int> stack;
    
    if (visited[start_node]) {
        return;
    }
    
    stack.push_back(start_node);
    visited[start_node] = true;

    while (!stack.empty()) {
        int u = stack.back();
        stack.pop_back();

        for (int v : adj[u]) {
            if (!visited[v]) {
                visited[v] = true;
                stack.push_back(v);
            }
        }
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n, e;
    std::cin >> n >> e;

    std::vector<std::vector<int>> adj(n);
    std::vector<std::vector<int>> rev_adj(n);
    std::vector<std::pair<int, int>> edges;
    edges.reserve(e);

    for (int i = 0; i < e; ++i) {
        int u, v;
        std::cin >> u >> v;
        adj[u].push_back(v);
        rev_adj[v].push_back(u);
        edges.push_back({u, v});
    }

    int start_node, end_node;
    std::cin >> start_node >> end_node;

    std::vector<bool> reachable_from_start(n, false);
    if (n > 0) {
        traverse(start_node, adj, reachable_from_start);
    }

    std::vector<bool> can_reach_end(n, false);
    if (n > 0) {
        traverse(end_node, rev_adj, can_reach_end);
    }

    std::vector<int> result_nodes;
    std::vector<bool> is_path_node(n, false);
    for (int i = 0; i < n; ++i) {
        if (reachable_from_start[i] && can_reach_end[i]) {
            result_nodes.push_back(i);
            is_path_node[i] = true;
        }
    }
    
    std::vector<std::pair<int, int>> result_edges;
    for (const auto& edge : edges) {
        if (is_path_node[edge.first] && is_path_node[edge.second]) {
            result_edges.push_back(edge);
        }
    }

    std::sort(result_edges.begin(), result_edges.end());

    std::cout << "Nodes set:\n";
    for (int node : result_nodes) {
        std::cout << node << "\n";
    }

    std::cout << "Edges set:\n";
    for (const auto& edge : result_edges) {
        std::cout << "(" << edge.first << ", " << edge.second << ")\n";
    }

    return 0;
}

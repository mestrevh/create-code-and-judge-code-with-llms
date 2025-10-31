/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <set>

std::vector<std::multiset<int>> adj;
std::vector<int> path;

void find_path(int u) {
    while (!adj[u].empty()) {
        int v = *adj[u].begin();
        adj[u].erase(adj[u].begin());
        adj[v].erase(adj[v].find(u));
        find_path(v);
    }
    path.push_back(u);
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int N, M;
    std::cin >> N >> M;

    if (M == 0) {
        std::cout << "Yes\n0\n";
        return 0;
    }

    adj.resize(N + 1);
    std::vector<int> degree(N + 1, 0);

    for (int i = 0; i < M; ++i) {
        int u, v;
        std::cin >> u >> v;
        adj[u].insert(v);
        adj[v].insert(u);
        degree[u]++;
        degree[v]++;
    }

    std::vector<int> odd_degree_nodes;
    for (int i = 0; i <= N; ++i) {
        if (degree[i] % 2 != 0) {
            odd_degree_nodes.push_back(i);
        }
    }

    int start_node = -1;
    if (odd_degree_nodes.empty()) {
        for (int i = 0; i <= N; ++i) {
            if (degree[i] > 0) {
                start_node = i;
                break;
            }
        }
    } else if (odd_degree_nodes.size() == 2) {
        start_node = odd_degree_nodes[0];
    } else {
        std::cout << "No\n";
        return 0;
    }
    
    if (start_node == -1) {
        std::cout << "No\n";
        return 0;
    }
    
    find_path(start_node);

    if (path.size() != M + 1) {
        std::cout << "No\n";
    } else {
        std::cout << "Yes\n";
        std::reverse(path.begin(), path.end());
        for (size_t i = 0; i < path.size(); ++i) {
            std::cout << path[i] << (i == path.size() - 1 ? "" : " ");
        }
        std::cout << "\n";
    }

    return 0;
}

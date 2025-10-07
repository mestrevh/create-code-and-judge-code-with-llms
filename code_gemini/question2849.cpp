/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <queue>
#include <functional>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n, m;
    std::cin >> n >> m;

    std::vector<std::vector<int>> adj(n + 1);
    std::vector<int> in_degree(n + 1, 0);

    for (int i = 0; i < m; ++i) {
        int u, v;
        std::cin >> u >> v;
        adj[v].push_back(u);
        in_degree[u]++;
    }

    std::priority_queue<int, std::vector<int>, std::greater<int>> pq;

    for (int i = 1; i <= n; ++i) {
        if (in_degree[i] == 0) {
            pq.push(i);
        }
    }

    std::vector<int> result;
    while (!pq.empty()) {
        int u = pq.top();
        pq.pop();
        result.push_back(u);

        for (int v : adj[u]) {
            in_degree[v]--;
            if (in_degree[v] == 0) {
                pq.push(v);
            }
        }
    }

    if (result.size() == n) {
        for (size_t i = 0; i < result.size(); ++i) {
            std::cout << result[i] << (i == result.size() - 1 ? "" : " ");
        }
        std::cout << '\n';
    } else {
        std::cout << "Impossible" << '\n';
    }

    return 0;
}

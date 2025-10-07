/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <queue>

void bfs(int start_node, std::vector<std::vector<int>>& adj, std::vector<bool>& visited, std::vector<int>& color, std::vector<int>& component_nodes) {
    std::queue<int> q;
    q.push(start_node);
    visited[start_node] = true;
    color[start_node] = 0;
    component_nodes.push_back(start_node);

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v : adj[u]) {
            if (!visited[v]) {
                visited[v] = true;
                color[v] = 1 - color[u];
                q.push(v);
                component_nodes.push_back(v);
            }
        }
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int D, P, R, B;
    std::cin >> D >> P >> R >> B;

    int N = D + P;
    std::vector<int> cost_d(D + 1);
    std::vector<int> cost_p(P + 1);
    std::vector<std::vector<int>> adj(N + 1);
    std::vector<bool> visited(N + 1, false);
    std::vector<int> color(N + 1, -1);

    for (int i = 1; i <= D; ++i) std::cin >> cost_d[i];
    for (int i = 1; i <= P; ++i) std::cin >> cost_p[i];

    for (int i = 0; i < R; ++i) {
        int u, v;
        std::cin >> u >> v;
        adj[u].push_back(D + v);
        adj[D + v].push_back(u);
    }

    std::vector<std::pair<std::pair<int, int>, std::pair<int, int>>> components_options;

    for (int i = 1; i <= N; ++i) {
        if (!visited[i]) {
            std::vector<int> component_nodes;
            bfs(i, adj, visited, color, component_nodes);

            int n1 = 0, c1 = 0;
            int total_switch_cost = 0;

            for (int node : component_nodes) {
                bool is_initially_pd = (node <= D);
                if (is_initially_pd) {
                    total_switch_cost += cost_d[node];
                } else {
                    total_switch_cost += cost_p[node - D];
                }

                if (color[node] == 0) { // Coloring A: this node is PD
                    n1++;
                    if (!is_initially_pd) { // Was PRISM, needs switch
                        c1 += cost_p[node - D];
                    }
                } else { // Coloring A: this node is PRISM
                    if (is_initially_pd) { // Was PD, needs switch
                        c1 += cost_d[node];
                    }
                }
            }
            int n2 = component_nodes.size() - n1;
            int c2 = total_switch_cost - c1;
            components_options.push_back({{n1, c1}, {n2, c2}});
        }
    }

    const int INF = 1e9;
    std::vector<int> dp(N + 1, INF);
    dp[0] = 0;

    for (const auto& options : components_options) {
        int n1 = options.first.first;
        int c1 = options.first.second;
        int n2 = options.second.first;
        int c2 = options.second.second;

        std::vector<int> next_dp(N + 1, INF);
        for (int k = 0; k <= N; ++k) {
            if (dp[k] != INF) {
                if (k + n1 <= N) {
                    next_dp[k + n1] = std::min(next_dp[k + n1], dp[k] + c1);
                }
                if (k + n2 <= N) {
                    next_dp[k + n2] = std::min(next_dp[k + n2], dp[k] + c2);
                }
            }
        }
        dp = next_dp;
    }

    int max_pd = 0;
    for (int k = N; k >= 0; --k) {
        if (dp[k] <= B) {
            max_pd = k;
            break;
        }
    }

    int min_pd_valid = -1;
    for (int k = 0; k <= N; ++k) {
        if (dp[k] <= B) {
            min_pd_valid = k;
            break;
        }
    }
    
    int max_prism = N - min_pd_valid;

    std::cout << max_pd << " " << max_prism << std::endl;

    return 0;
}

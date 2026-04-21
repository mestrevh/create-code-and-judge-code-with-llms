/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main() {
    // Fast I/O optimization for Competitive Programming
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    // Read N, check for valid input
    if (!(cin >> N)) return 0;

    // f[i] is the domino knocked down by domino i
    vector<int> f(N + 1);
    vector<int> in_deg(N + 1, 0);
    for (int i = 1; i <= N; ++i) {
        cin >> f[i];
        in_deg[f[i]]++;
    }

    // dp[i] will store the maximum domino ID reachable from domino i
    vector<int> dp(N + 1, -1);
    // is_cycle[i] helps identify nodes that belong to a cycle
    vector<bool> is_cycle(N + 1, true);
    // topo_order stores nodes that are not part of any cycle
    vector<int> topo_order;
    queue<int> q;

    // Kahn's Algorithm to find all nodes not in cycles
    for (int i = 1; i <= N; ++i) {
        if (in_deg[i] == 0) {
            q.push(i);
        }
    }

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        topo_order.push_back(u);
        is_cycle[u] = false;
        int v = f[u];
        if (--in_deg[v] == 0) {
            q.push(v);
        }
    }

    // Identify all cycles and set their DP values
    // In a functional graph, each cycle's nodes all reach the same maximum: the max ID in that cycle.
    for (int i = 1; i <= N; ++i) {
        if (is_cycle[i] && dp[i] == -1) {
            vector<int> cycle;
            int curr = i;
            int max_val = 0;
            // Traverse the cycle
            while (dp[curr] == -1) {
                dp[curr] = -2; // Temporary visiting marker
                cycle.push_back(curr);
                max_val = max(max_val, curr);
                curr = f[curr];
            }
            // Set max_val for all nodes in this cycle
            for (int node : cycle) {
                dp[node] = max_val;
            }
        }
    }

    // Process non-cycle nodes in reverse topological order.
    // Each node u points to f(u). If we process in reverse topo order,
    // dp[f[u]] will already be calculated when we process u.
    // The max reachable from u is either u itself or the max reachable from its successor f(u).
    for (int i = (int)topo_order.size() - 1; i >= 0; --i) {
        int u = topo_order[i];
        dp[u] = max(u, dp[f[u]]);
    }

    // Final result output
    for (int i = 1; i <= N; ++i) {
        cout << dp[i] << "\n";
    }

    return 0;
}
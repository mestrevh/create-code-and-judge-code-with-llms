/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

/**
 * Problem: Find the number of articulation points (critical places) in an undirected graph.
 * Constraints: N <= 50,000, 1s time limit.
 * Algorithm: Tarjan's/Hopcroft-Tarjan Articulation Points algorithm - O(V + E).
 */

const int MAXN = 50005;
vector<int> adj[MAXN];
int tin[MAXN], low[MAXN], timer;
bool is_ap[MAXN];

void dfs(int u, int p) {
    tin[u] = low[u] = ++timer;
    int children = 0;
    for (int v : adj[u]) {
        if (v == p) continue;
        if (tin[v]) {
            // Back-edge
            low[u] = min(low[u], tin[v]);
        } else {
            // Tree-edge
            dfs(v, u);
            low[u] = min(low[u], low[v]);
            if (low[v] >= tin[u] && p != -1) {
                is_ap[u] = true;
            }
            children++;
        }
    }
    // Root special case
    if (p == -1 && children > 1) {
        is_ap[u] = true;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    while (cin >> n && n != 0) {
        // Reset data structures for the new test case
        for (int i = 1; i <= n; i++) {
            adj[i].clear();
            tin[i] = 0;
            low[i] = 0;
            is_ap[i] = false;
        }
        timer = 0;

        int s;
        // Parse the block of connections
        while (cin >> s && s != 0) {
            string line;
            getline(cin, line);
            stringstream ss(line);
            int v;
            while (ss >> v) {
                if (s >= 1 && s <= n && v >= 1 && v <= n) {
                    adj[s].push_back(v);
                    adj[v].push_back(s);
                }
            }
        }

        // Run DFS from all nodes to handle potentially disconnected components
        // though the problem states the graph is connected.
        for (int i = 1; i <= n; i++) {
            if (!tin[i]) {
                dfs(i, -1);
            }
        }

        // Count articulation points
        int critical_count = 0;
        for (int i = 1; i <= n; i++) {
            if (is_ap[i]) {
                critical_count++;
            }
        }

        cout << critical_count << "\n";
    }

    return 0;
}
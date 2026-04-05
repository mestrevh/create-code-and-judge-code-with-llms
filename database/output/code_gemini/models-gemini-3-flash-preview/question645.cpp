/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * Problem Analysis:
 * The problem asks if an undirected graph can be oriented into a strongly connected directed graph.
 * According to Robbins' Theorem, this is possible if and only if the graph is connected and 
 * has no bridges (i.e., it is 2-edge-connected).
 */

const int MAXN = 1005;
vector<int> adj[MAXN];
int tin[MAXN], low[MAXN];
bool visited[MAXN];
int timer;
bool has_bridge;

void dfs(int u, int p) {
    visited[u] = true;
    tin[u] = low[u] = timer++;
    for (int v : adj[u]) {
        if (v == p) continue;
        if (visited[v]) {
            // Found a back-edge
            low[u] = min(low[u], tin[v]);
        } else {
            // Tree-edge
            dfs(v, u);
            low[u] = min(low[u], low[v]);
            // Bridge condition for undirected graph
            if (low[v] > tin[u]) {
                has_bridge = true;
            }
        }
    }
}

int main() {
    // Standard I/O optimization
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    while (cin >> n >> m && (n != 0 || m != 0)) {
        // Resetting data structures for each test case
        for (int i = 1; i <= n; i++) {
            adj[i].clear();
            visited[i] = false;
            tin[i] = -1;
            low[i] = -1;
        }
        
        for (int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        timer = 0;
        has_bridge = false;

        // Perform DFS from the first node
        dfs(1, -1);

        // Check if the graph is connected
        bool connected = true;
        for (int i = 1; i <= n; i++) {
            if (!visited[i]) {
                connected = false;
                break;
            }
        }

        // According to Robbins' Theorem: must be connected and bridge-free
        if (connected && !has_bridge) {
            cout << "S" << endl;
        } else {
            cout << "N" << endl;
        }
    }

    return 0;
}
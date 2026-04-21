/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>

using namespace std;

/**
 * Problem: Ir e Vir (Strongly Connected Components check)
 * Approach: A graph is strongly connected if and only if from an arbitrary node 'u', 
 * all other nodes are reachable in the original graph AND all other nodes can 
 * reach 'u' (which is equivalent to 'u' reaching all nodes in the reversed graph).
 * Complexity: O(N + M) per test case.
 */

const int MAXN = 2005;
vector<int> adj[MAXN];
vector<int> rev_adj[MAXN];
bool visited[MAXN];

void dfs(int u, vector<int> g[]) {
    visited[u] = true;
    for (int v : g[u]) {
        if (!visited[v]) {
            dfs(v, g);
        }
    }
}

int main() {
    // Optimization for Competitive Programming I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    while (cin >> n >> m && (n != 0 || m != 0)) {
        // Clear adjacency lists for each test case
        for (int i = 1; i <= n; ++i) {
            adj[i].clear();
            rev_adj[i].clear();
        }

        for (int i = 0; i < m; ++i) {
            int v, w, p;
            cin >> v >> w >> p;
            // P = 1: v -> w
            // P = 2: v <-> w
            adj[v].push_back(w);
            rev_adj[w].push_back(v);
            if (p == 2) {
                adj[w].push_back(v);
                rev_adj[v].push_back(w);
            }
        }

        bool strongly_connected = true;

        // 1. Check if node 1 can reach all other nodes in G
        for (int i = 1; i <= n; ++i) visited[i] = false;
        dfs(1, adj);
        for (int i = 1; i <= n; ++i) {
            if (!visited[i]) {
                strongly_connected = false;
                break;
            }
        }

        // 2. Check if all other nodes can reach node 1 in G 
        // (Equivalent to checking if 1 can reach all nodes in G_transpose)
        if (strongly_connected) {
            for (int i = 1; i <= n; ++i) visited[i] = false;
            dfs(1, rev_adj);
            for (int i = 1; i <= n; ++i) {
                if (!visited[i]) {
                    strongly_connected = false;
                    break;
                }
            }
        }

        if (strongly_connected) {
            cout << "1\n";
        } else {
            cout << "0\n";
        }
    }

    return 0;
}
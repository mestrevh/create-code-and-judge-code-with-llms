/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

/**
 * Persona: Grandmaster in Competitive Programming, C++ Expert.
 * Problem: MaxMin - Calculate maximum minimum distance (dmax) from a source S
 * in a connected graph G and count how many vertices (Nmax) are at that distance.
 * Algorithm: Breadth-First Search (BFS) for single-source shortest path in unweighted graphs.
 * Complexity: O(C * (N + E)) where C is number of cases, N vertices, E edges.
 */

int main() {
    // Standard I/O optimization for competitive programming
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int C;
    if (!(cin >> C)) return 0;

    for (int k = 0; k < C; ++k) {
        int N, S;
        if (!(cin >> N >> S)) break;

        // Adjacency list to store the graph
        vector<vector<int>> adj(N);
        for (int i = 0; i < N; ++i) {
            int D;
            cin >> D;
            adj[i].resize(D);
            for (int j = 0; j < D; ++j) {
                cin >> adj[i][j];
            }
        }

        // dist[i] will store the shortest distance from S to vertex i
        // Initialized to -1 to represent unvisited nodes
        vector<int> dist(N, -1);
        queue<int> q;

        dist[S] = 0;
        q.push(S);

        int dmax = 0;
        int nmax = 0;

        // BFS traversal
        while (!q.empty()) {
            int u = q.front();
            q.pop();

            // Since BFS processes nodes in non-decreasing order of distance,
            // we can maintain dmax and nmax as we pop from the queue.
            if (dist[u] > dmax) {
                dmax = dist[u];
                nmax = 1;
            } else if (dist[u] == dmax) {
                nmax++;
            }

            for (int v : adj[u]) {
                if (dist[v] == -1) {
                    dist[v] = dist[u] + 1;
                    q.push(v);
                }
            }
        }

        // Output result for case k: k dmax Nmax
        cout << k << " " << dmax << " " << nmax << "\n";
    }

    return 0;
}
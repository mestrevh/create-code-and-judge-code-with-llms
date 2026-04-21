/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

/**
 * Problem: aMAZEing! - Pt.2
 * Persona: Competitive Programming Grandmaster
 * Solution: Dijkstra's Algorithm on a grid to find the minimum cost to reach any boundary cell.
 * Complexity: O(T * N^2 * log(N^2)), where T is the number of test cases and N <= 100.
 */

const int INF = 2000000007; // Slightly more than 2*10^9

struct Edge {
    int to, weight;
};

// Function to check if a cell is on the boundary of an N x N grid
inline bool isBoundary(int u, int N) {
    int r = u / N, c = u % N;
    return r == 0 || r == N - 1 || c == 0 || c == N - 1;
}

int main() {
    // Standard competitive programming I/O optimization
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, X;
    int caseNum = 1;
    // Read N and X until EOF
    while (cin >> N >> X) {
        int totalWalls = 2 * (N * N - N);
        vector<int> wallCosts(totalWalls);
        for (int i = 0; i < totalWalls; ++i) {
            cin >> wallCosts[i];
        }

        // Build adjacency list for the N*N grid cells
        vector<vector<Edge>> adj(N * N);
        int wallIdx = 0;
        for (int r = 0; r < N; ++r) {
            // Read vertical walls for current row
            for (int c = 0; c < N - 1; ++c) {
                int cost = wallCosts[wallIdx++];
                int u = r * N + c;
                int v = r * N + c + 1;
                adj[u].push_back({v, cost});
                adj[v].push_back({u, cost});
            }
            // Read horizontal walls below current row
            if (r < N - 1) {
                for (int c = 0; c < N; ++c) {
                    int cost = wallCosts[wallIdx++];
                    int u = r * N + c;
                    int v = (r + 1) * N + c;
                    adj[u].push_back({v, cost});
                    adj[v].push_back({u, cost});
                }
            }
        }

        // If the starting cell is already on the boundary, force is 0
        if (isBoundary(X, N)) {
            cout << "caso " << caseNum++ << ": 0\n";
            continue;
        }

        // Dijkstra's algorithm to find the minimum cost to any boundary cell
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> dist(N * N, INF);

        dist[X] = 0;
        pq.push({0, X});

        int result = INF;
        while (!pq.empty()) {
            int d = pq.top().first;
            int u = pq.top().second;
            pq.pop();

            if (d > dist[u]) continue;

            // Goal check: reach a cell on the boundary
            if (isBoundary(u, N)) {
                result = d;
                break;
            }

            for (const auto& edge : adj[u]) {
                if (dist[u] + edge.weight < dist[edge.to]) {
                    dist[edge.to] = dist[u] + edge.weight;
                    pq.push({dist[edge.first == 0 ? edge.to : edge.to], edge.to});
                }
            }
        }

        cout << "caso " << caseNum++ << ": " << result << "\n";
    }

    return 0;
}
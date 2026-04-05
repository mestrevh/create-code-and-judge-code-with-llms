/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

/**
 * Problem: Pizzaria (ICPC/Maratona style)
 * Logic: The delivery route starts at the pizzeria (node 1) for every single order, 
 * goes to house Xi, and returns to node 1. Since roads are undirected, the 
 * cost of a single delivery Xi is 2 * dist(1, Xi).
 * Total time = Sum for i from 1 to K of (2 * dist(1, Xi)).
 * Dijkstra's algorithm from node 1 is sufficient to find all dist(1, Xi).
 */

const long long INF = 1e18;
vector<pair<int, int>> adj[10005];
long long dist[10005];

void dijkstra(int start, int n) {
    for (int i = 1; i <= n; ++i) {
        dist[i] = INF;
    }
    dist[start] = 0;
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
    pq.push({0, start});

    while (!pq.empty()) {
        long long d = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        if (d > dist[u]) continue;

        for (auto& edge : adj[u]) {
            int v = edge.first;
            int weight = edge.second;
            if (dist[u] + (long long)weight < dist[v]) {
                dist[v] = dist[u] + (long long)weight;
                pq.push({dist[v], v});
            }
        }
    }
}

int main() {
    // Fast I/O optimization
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    if (!(cin >> T)) return 0;
    for (int t = 1; t <= T; ++t) {
        int N, M;
        if (!(cin >> N >> M)) break;

        // Reset graph for each case
        for (int i = 1; i <= N; ++i) {
            adj[i].clear();
        }

        // Build undirected graph
        for (int i = 0; i < M; ++i) {
            int u, v, c;
            cin >> u >> v >> c;
            if (u <= N && v <= N) {
                adj[u].push_back({v, c});
                adj[v].push_back({u, c});
            }
        }

        // Run Dijkstra from Pizzeria (Node 1)
        dijkstra(1, N);

        int K;
        cin >> K;
        long long total_time = 0;
        for (int i = 0; i < K; ++i) {
            int house;
            cin >> house;
            if (dist[house] != INF) {
                total_time += 2LL * dist[house];
            }
        }

        // Output formatting: "caso A: B"
        cout << "caso " << t << ": " << total_time << "\n";
    }

    return 0;
}
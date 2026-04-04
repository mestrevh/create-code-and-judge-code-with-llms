/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <queue>
#include <iomanip>

using namespace std;

const double INF = 1e18;

struct Edge {
    int to;
    double a, b;
};

vector<Edge> adj[1005];
double dist[1005];
int N, M;

double dijkstra(double t) {
    for (int i = 1; i <= N; ++i) dist[i] = INF;
    dist[1] = 0.0;
    priority_queue<pair<double, int>, vector<pair<double, int>>, greater<pair<double, int>>> pq;
    pq.push({0.0, 1});

    while (!pq.empty()) {
        double d = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        if (d > dist[u]) continue;
        if (u == N) return d;

        for (const auto& e : adj[u]) {
            double weight = e.a * t + e.b;
            if (dist[e.to] > d + weight) {
                dist[e.to] = d + weight;
                pq.push({dist[e.to], e.to});
            }
        }
    }
    return dist[N];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    while (cin >> N >> M) {
        for (int i = 1; i <= N; ++i) adj[i].clear();
        for (int i = 0; i < M; ++i) {
            int u, v;
            double a, b;
            cin >> u >> v >> a >> b;
            adj[u].push_back({v, a, b});
            adj[v].push_back({u, a, b});
        }

        double low = 0.0, high = 1440.0;
        for (int i = 0; i < 100; ++i) {
            double m1 = (2.0 * low + high) / 3.0;
            double m2 = (low + 2.0 * high) / 3.0;
            if (dijkstra(m1) < dijkstra(m2)) {
                low = m1;
            } else {
                high = m2;
            }
        }
        cout << fixed << setprecision(5) << dijkstra(low) << "\n";
    }
    return 0;
}
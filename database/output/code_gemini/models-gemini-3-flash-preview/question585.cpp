/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

const long long INF = 1e18;

struct Edge {
    int to;
    int weight;
};

struct Cycle {
    long long len;
    vector<int> nodes;
};

int S, T;
vector<Edge> adj[10005];
int p_node[10005];
int depth[10005];
bool visited[10005];
int weight_to_p[10005];
vector<Cycle> cycles;

void find_cycles(int u, int p, int d, int w_p) {
    visited[u] = true;
    p_node[u] = p;
    depth[u] = d;
    weight_to_p[u] = w_p;
    for (auto& edge : adj[u]) {
        if (edge.to == p) continue;
        if (visited[edge.to]) {
            if (depth[edge.to] < depth[u]) {
                Cycle cycle;
                cycle.len = edge.weight;
                int curr = u;
                while (curr != edge.to) {
                    cycle.nodes.push_back(curr);
                    cycle.len += (long long)weight_to_p[curr];
                    curr = p_node[curr];
                }
                cycle.nodes.push_back(edge.to);
                cycles.push_back(cycle);
            }
        } else {
            find_cycles(edge.to, u, d + 1, edge.weight);
        }
    }
}

long long dists[10005];
void dijkstra(int start) {
    fill(dists + 1, dists + S + 1, INF);
    dists[start] = 0;
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
    pq.push({0, start});
    while (!pq.empty()) {
        long long d = pq.top().first;
        int u = pq.top().second;
        pq.pop();
        if (d > dists[u]) continue;
        for (auto& edge : adj[u]) {
            if (dists[u] + (long long)edge.weight < dists[edge.to]) {
                dists[edge.to] = dists[u] + edge.weight;
                pq.push({dists[edge.to], edge.to});
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    if (!(cin >> S >> T)) return 0;
    for (int i = 0; i < T; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    for (int i = 1; i <= S; i++) {
        if (!visited[i]) {
            find_cycles(i, -1, 0, 0);
        }
    }

    int Q;
    if (!(cin >> Q)) return 0;
    while (Q--) {
        int X;
        long long M;
        cin >> X >> M;
        dijkstra(X);
        long long ans = INF;
        for (const auto& cycle : cycles) {
            if (cycle.len >= M) {
                long long min_d_to_cycle = INF;
                for (int node : cycle.nodes) {
                    if (dists[node] < min_d_to_cycle) {
                        min_d_to_cycle = dists[node];
                    }
                }
                if (min_d_to_cycle != INF) {
                    long long total_dist = 2 * min_d_to_cycle + cycle.len;
                    if (total_dist < ans) {
                        ans = total_dist;
                    }
                }
            }
        }
        if (ans == INF) {
            cout << -1 << "\n";
        } else {
            cout << ans << "\n";
        }
    }

    return 0;
}
/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

const long long INF = 1e16;

struct Spell {
    int cost, damage;
};

long long dp[1005];
vector<int> adj[1005];
long long room_cost[1005];
long long dist[1005];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int M, N, G, K;
    while (cin >> M >> N >> G >> K && (M || N || G || K)) {
        vector<Spell> spells(M);
        for (int i = 0; i < M; ++i) {
            cin >> spells[i].cost >> spells[i].damage;
        }

        for (int i = 0; i <= 1000; ++i) dp[i] = INF;
        dp[0] = 0;
        for (int i = 0; i < M; ++i) {
            for (int j = 1; j <= 1000; ++j) {
                int prev = j - spells[i].damage;
                if (prev < 0) prev = 0;
                if (dp[prev] != INF) {
                    if (dp[prev] + (long long)spells[i].cost < dp[j]) {
                        dp[j] = dp[prev] + (long long)spells[i].cost;
                    }
                }
            }
        }

        for (int i = 1; i <= N; ++i) {
            adj[i].clear();
            room_cost[i] = 0;
            dist[i] = INF;
        }

        for (int i = 0; i < G; ++i) {
            int u, v;
            cin >> u >> v;
            if (u >= 1 && u <= N && v >= 1 && v <= N) {
                adj[u].push_back(v);
                adj[v].push_back(u);
            }
        }

        for (int i = 0; i < K; ++i) {
            int r, h;
            cin >> r >> h;
            if (r >= 1 && r <= N) {
                if (dp[h] >= INF) {
                    room_cost[r] = INF;
                } else if (room_cost[r] < INF) {
                    room_cost[r] += dp[h];
                }
            }
        }

        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
        if (room_cost[1] < INF) {
            dist[1] = room_cost[1];
            pq.push({dist[1], 1});
        }

        while (!pq.empty()) {
            long long d = pq.top().first;
            int u = pq.top().second;
            pq.pop();

            if (d > dist[u]) continue;

            for (int v : adj[u]) {
                if (room_cost[v] < INF && dist[u] + room_cost[v] < dist[v]) {
                    dist[v] = dist[u] + room_cost[v];
                    pq.push({dist[v], v});
                }
            }
        }

        if (dist[N] >= INF) {
            cout << -1 << "\n";
        } else {
            cout << dist[N] << "\n";
        }
    }

    return 0;
}


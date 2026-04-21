/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int V, A;
    if (!(cin >> V >> A)) return 0;

    vector<vector<pair<int,int>>> adj(V+1);
    vector<vector<int>> idxSum(V+1);
    vector<long long> sumIdx(V+1, 0);

    for (int i = 0; i < A; i++) {
        int S, D, C;
        cin >> S >> D >> C;
        adj[S].push_back({D, C});
        adj[D].push_back({S, C});
        sumIdx[S] += D;
        sumIdx[D] += S;
    }

    vector<int> color(V+1, 0);
    for (int i = 1; i <= V; i++) color[i] = (sumIdx[i] % 2 == 0) ? 0 : 1;

    const long long INF = (1LL<<60);
    vector<vector<long long>> dist(V+1, vector<long long>(V+1, INF));
    for (int i = 1; i <= V; i++) dist[i][i] = 0;

    for (int u = 1; u <= V; u++) {
        priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<pair<long long,int>>> pq;
        dist[u][u] = 0;
        pq.push({0, u});
        while (!pq.empty()) {
            auto [d, x] = pq.top();
            pq.pop();
            if (d != dist[u][x]) continue;
            for (auto [y, w] : adj[x]) {
                if (dist[u][y] > d + w) {
                    dist[u][y] = d + w;
                    pq.push({dist[u][y], y});
                }
            }
        }
    }

    auto pick = [&](int col) -> pair<int,int> {
        long long bestD = -1;
        pair<int,int> bestPair = {1,2};
        for (int i = 1; i <= V; i++) if (color[i] == col) {
            for (int j = i+1; j <= V; j++) if (color[j] == col) {
                long long d = dist[i][j];
                if (d == INF) continue;
                if (d > bestD) {
                    bestD = d;
                    bestPair = {i, j};
                } else if (d == bestD) {
                    if (i < bestPair.first || (i == bestPair.first && j < bestPair.second))
                        bestPair = {i, j};
                }
            }
        }
        for (int i = 1; i <= V; i++) if (color[i] == col) {
            for (int j = i+1; j <= V; j++) if (color[j] == col) {
                if (dist[i][j] == INF) continue;
                long long d = dist[i][j];
                if (d > bestD) {
                    bestD = d;
                    bestPair = {i, j};
                } else if (d == bestD) {
                    if (i < bestPair.first || (i == bestPair.first && j < bestPair.second))
                        bestPair = {i, j};
                }
            }
        }
        return bestPair;
    };

    auto red = pick(0);
    auto blue = pick(1);

    cout << red.first << " " << red.second << "\n";
    cout << blue.first << " " << blue.second << "\n";
    return 0;
}
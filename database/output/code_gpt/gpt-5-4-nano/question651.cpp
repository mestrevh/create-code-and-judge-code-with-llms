/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int M, N, G, K;
    while ( (cin >> M >> N >> G >> K) ) {
        if (M == 0 && N == 0 && G == 0 && K == 0) break;

        const int INF = 1e9;

        vector<int> mana(M), dmg(M);
        for (int i = 0; i < M; i++) cin >> mana[i] >> dmg[i];

        vector<vector<int>> g(N + 1);
        for (int i = 0; i < G; i++) {
            int A, B;
            cin >> A >> B;
            if (A >= 1 && A <= N && B >= 1 && B <= N) {
                g[A].push_back(B);
                g[B].push_back(A);
            }
        }

        vector<int> monsters(N + 1, 0);
        for (int i = 0; i < K; i++) {
            int s, hp;
            cin >> s >> hp;
            if (s >= 1 && s <= N) monsters[s] += hp;
        }

        int maxHP = 0;
        for (int i = 1; i <= N; i++) maxHP = max(maxHP, monsters[i]);

        vector<int> best(maxHP + 1, INF);
        best[0] = 0;
        for (int hp = 0; hp <= maxHP; hp++) {
            if (best[hp] == INF) continue;
            for (int i = 0; i < M; i++) {
                int nd = min(maxHP, hp + dmg[i]);
                best[nd] = min(best[nd], best[hp] + mana[i]);
            }
        }

        vector<int> cost(N + 1, INF);
        for (int i = 1; i <= N; i++) {
            int hp = monsters[i];
            if (hp == 0) cost[i] = 0;
            else {
                int c = best[hp];
                if (c == INF) cost[i] = INF;
                else cost[i] = c;
            }
        }

        if (cost[1] == INF) {
            cout << -1 << "\n";
            continue;
        }

        vector<int> dist(N + 1, INF);
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        dist[1] = cost[1];
        pq.push({dist[1], 1});

        while (!pq.empty()) {
            auto [d, u] = pq.top();
            pq.pop();
            if (d != dist[u]) continue;
            for (int v : g[u]) {
                if (cost[v] == INF) continue;
                long long nd = (long long)d + cost[v];
                if (nd < dist[v]) {
                    dist[v] = (int)nd;
                    pq.push({dist[v], v});
                }
            }
        }

        if (dist[N] == INF) cout << -1 << "\n";
        else cout << dist[N] << "\n";
    }
    return 0;
}
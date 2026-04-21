/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, E, S, M;
    if (!(cin >> N >> E >> S >> M)) return 0;

    vector<long long> T(N);
    for (int i = 0; i < N; i++) cin >> T[i];

    vector<vector<int>> g(N);
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
    }

    const long long INF = (1LL<<62);
    vector<long long> dist(N, INF);

    auto canEnter = [&](int v, long long time)->bool{
        if (T[v] == 0) return false;
        long long r = time % T[v];
        return r >= (T[v]-1);
    };

    priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<pair<long long,int>>> pq;

    if (E == S) {
        cout << 0 << " minutos\n";
        return 0;
    }

    dist[E] = 0;
    pq.push({0, E});

    while (!pq.empty()) {
        auto [d,u] = pq.top();
        pq.pop();
        if (d != dist[u]) continue;

        for (int v : g[u]) {
            long long nd = d + 1;
            if (!canEnter(v, nd)) continue;
            if (nd < dist[v]) {
                dist[v] = nd;
                pq.push({nd, v});
            }
        }
    }

    if (dist[S] == INF) {
        cout << "Araragi morreu\n";
    } else {
        cout << dist[S] << " minutos\n";
    }
    return 0;
}
/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int C, V;
    if (!(cin >> C >> V)) return 0;

    vector<vector<pair<int,int>>> adj(C + 1);
    for (int i = 0; i < V; i++) {
        int c1, c2, g;
        cin >> c1 >> c2 >> g;
        adj[c1].push_back({c2, g});
        adj[c2].push_back({c1, g});
    }

    const long long INF = (1LL<<62);
    vector<array<long long,2>> dist(C + 1);
    for (int i = 1; i <= C; i++) dist[i] = {INF, INF};
    dist[1][0] = 0;

    using State = tuple<long long,int,int>;
    priority_queue<State, vector<State>, greater<State>> pq;
    pq.push({0, 1, 0});

    while (!pq.empty()) {
        auto [d, u, p] = pq.top();
        pq.pop();
        if (d != dist[u][p]) continue;
        for (auto [v, w] : adj[u]) {
            int np = p ^ 1;
            long long nd = d + w;
            if (nd < dist[v][np]) {
                dist[v][np] = nd;
                pq.push({nd, v, np});
            }
        }
    }

    long long ans = dist[C][0];
    if (ans >= INF/2) ans = -1;
    cout << ans << "\n";
    return 0;
}
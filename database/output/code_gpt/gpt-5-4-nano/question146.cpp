/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int to;
    int T;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, E, S, M;
    if (!(cin >> N >> E >> S >> M)) return 0;

    vector<vector<Edge>> g(N);
    for (int i = 0; i < M; i++) {
        int A, B, T;
        cin >> A >> B >> T;
        g[A].push_back({B, T});
    }

    const long long INF = (1LL<<60);
    vector<array<long long,3>> dist(N);
    for (int i = 0; i < N; i++) dist[i] = {INF, INF, INF};

    using State = pair<long long, pair<int,int>>;
    priority_queue<State, vector<State>, greater<State>> pq;

    dist[E][0] = 0;
    pq.push({0, {E, 0}});

    auto relax = [&](int u, int rem, int v, int T, long long dcur, long long &best){
        int mod = rem % 3;
        bool opens = (T == 1) ? (mod == 0) : (mod != 0);
        long long wait = opens ? 0 : (mod == 1 ? 1 : 2);
        long long nd = dcur + wait + 1;
        int nrem = (int)(nd % 3);
        if (nd < dist[v][nrem]) {
            dist[v][nrem] = nd;
            pq.push({nd, {v, nrem}});
        }
    };

    while (!pq.empty()) {
        auto [d, st] = pq.top();
        pq.pop();
        int u = st.first;
        int rem = st.second;
        if (d != dist[u][rem]) continue;

        if (u == S) {
            break;
        }

        for (const auto &e : g[u]) {
            int v = e.to;
            int T = e.T;
            int mod = rem;
            bool opens = (T == 1) ? (mod == 0) : (mod != 0);
            long long wait = opens ? 0 : (mod == 1 ? 1 : 2);
            long long nd = d + wait + 1;
            int nrem = (int)(nd % 3);
            if (nd < dist[v][nrem]) {
                dist[v][nrem] = nd;
                pq.push({nd, {v, nrem}});
            }
        }
    }

    long long ans = min({dist[S][0], dist[S][1], dist[S][2]});
    if (ans >= INF/2) cout << "*\n";
    else cout << ans << "\n";
    return 0;
}
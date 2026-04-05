/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int u, v;
    double A, B;
};

static const double TMAX = 1440.0;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cout.setf(std::ios::fixed);
    cout << setprecision(5);

    while ( (cin >> N >> M) ) {
        vector<Edge> edges;
        edges.reserve(M);
        for (int i = 0; i < M; i++) {
            int I, J;
            long long A, B;
            cin >> I >> J >> A >> B;
            Edge e;
            e.u = I - 1;
            e.v = J - 1;
            e.A = (double)A;
            e.B = (double)B;
            edges.push_back(e);
        }

        vector<vector<pair<int,int>>> adj(N);
        adj.assign(N, {});
        for (int i = 0; i < M; i++) {
            auto &e = edges[i];
            adj[e.u].push_back({e.v, i});
            adj[e.v].push_back({e.u, i});
        }

        auto dijkstra = [&](double t)->double{
            const double INF = 1e100;
            vector<double> dist(N, INF);
            using P = pair<double,int>;
            priority_queue<P, vector<P>, greater<P>> pq;
            dist[0] = 0.0;
            pq.push({0.0, 0});
            while(!pq.empty()){
                auto [d, x] = pq.top(); pq.pop();
                if (d != dist[x]) continue;
                if (x == N-1) return d;
                for (auto [to, idx] : adj[x]) {
                    auto &e = edges[idx];
                    double w = e.A * t + e.B;
                    double nd = d + w;
                    if (nd < dist[to]) {
                        dist[to] = nd;
                        pq.push({nd, to});
                    }
                }
            }
            return dist[N-1];
        };

        double best = -1.0;
        double left = 0.0, right = TMAX;

        auto maximize = [&]()->double{
            double l = left, r = right;
            for (int it = 0; it < 100; it++) {
                double m1 = l + (r - l) / 3.0;
                double m2 = r - (r - l) / 3.0;
                double f1 = dijkstra(m1);
                double f2 = dijkstra(m2);
                if (f1 < f2) l = m1;
                else r = m2;
            }
            double mid = (l + r) / 2.0;
            double fmid = dijkstra(mid);
            double fl = dijkstra(left);
            double fr = dijkstra(right);
            double ans = max({fl, fr, fmid});
            return ans;
        };

        best = maximize();
        cout << best + 1e-9 << "\n";
    }

    return 0;
}
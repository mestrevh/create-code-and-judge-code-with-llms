/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int L;
    if (!(cin >> L)) return 0;
    for (int tc = 0; tc < L; tc++) {
        int N;
        cin >> N;
        vector<long long> x(N), y(N);
        for (int i = 0; i < N; i++) cin >> x[i] >> y[i];

        vector<int> idxX(N), idxY(N);
        iota(idxX.begin(), idxX.end(), 0);
        iota(idxY.begin(), idxY.end(), 0);
        sort(idxX.begin(), idxX.end(), [&](int a, int b){
            if (x[a] != x[b]) return x[a] < x[b];
            return y[a] < y[b];
        });
        sort(idxY.begin(), idxY.end(), [&](int a, int b){
            if (y[a] != y[b]) return y[a] < y[b];
            return x[a] < x[b];
        });

        struct Edge{
            int u, v;
            long long w;
        };

        vector<Edge> edges;
        edges.reserve(2LL * (N - 1));

        auto addLine = [&](int a, int b){
            if (a == b) return;
            long long w = llabs(x[a] - x[b]) + llabs(y[a] - y[b]);
            edges.push_back({a, b, w});
        };

        for (int i = 0; i + 1 < N; i++) addLine(idxX[i], idxX[i+1]);
        for (int i = 0; i + 1 < N; i++) addLine(idxY[i], idxY[i+1]);

        sort(edges.begin(), edges.end(), [](const Edge& e1, const Edge& e2){
            if (e1.w != e2.w) return e1.w < e2.w;
            if (e1.u != e2.u) return e1.u < e2.u;
            return e1.v < e2.v;
        });

        vector<int> parent(N), rnk(N, 0);
        iota(parent.begin(), parent.end(), 0);
        function<int(int)> findp = [&](int a){
            while (parent[a] != a){
                parent[a] = parent[parent[a]];
                a = parent[a];
            }
            return a;
        };
        auto unite = [&](int a, int b){
            a = findp(a);
            b = findp(b);
            if (a == b) return false;
            if (rnk[a] < rnk[b]) swap(a, b);
            parent[b] = a;
            if (rnk[a] == rnk[b]) rnk[a]++;
            return true;
        };

        long long ans = 0;
        int cnt = 0;
        for (auto &e : edges) {
            if (unite(e.u, e.v)) {
                ans += e.w;
                cnt++;
                if (cnt == N - 1) break;
            }
        }

        cout << tc << ": " << ans << "\n";
    }
    return 0;
}
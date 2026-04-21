/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

struct DSU {
    vector<int> p, r;
    DSU(int n=0){init(n);}
    void init(int n){
        p.resize(n);
        r.assign(n,0);
        iota(p.begin(), p.end(), 0);
    }
    int find(int a){ return p[a]==a?a:p[a]=find(p[a]); }
    bool unite(int a,int b){
        a=find(a); b=find(b);
        if(a==b) return false;
        if(r[a]<r[b]) swap(a,b);
        p[b]=a;
        if(r[a]==r[b]) r[a]++;
        return true;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cout.setf(std::ios::fixed);
    cout << setprecision(2);

    while (cin >> N) {
        if (N == 0) break;
        vector<double> x(N), y(N);
        for (int i = 0; i < N; i++) cin >> x[i] >> y[i];

        vector<tuple<double,int,int>> edges;
        edges.reserve((size_t)N*(N-1)/2);
        for (int i = 0; i < N; i++) {
            for (int j = i+1; j < N; j++) {
                double dx = x[i] - x[j];
                double dy = y[i] - y[j];
                double d = sqrt(dx*dx + dy*dy);
                edges.emplace_back(d, i, j);
            }
        }

        sort(edges.begin(), edges.end(), [](const auto& a, const auto& b){
            return get<0>(a) < get<0>(b);
        });

        DSU dsu(N);
        double total = 0.0;
        int used = 0;
        for (auto &e : edges) {
            double w;
            int a, b;
            tie(w, a, b) = e;
            if (dsu.unite(a, b)) {
                total += w;
                used++;
                if (used == N-1) break;
            }
        }

        cout << total << "\n";
    }
    return 0;
}
/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

struct DSU {
    vector<int> p, r;
    DSU(int n=0){ init(n); }
    void init(int n){
        p.resize(n+1);
        r.assign(n+1,0);
        iota(p.begin(), p.end(), 0);
    }
    int find(int x){
        while(p[x]!=x){
            p[x]=p[p[x]];
            x=p[x];
        }
        return x;
    }
    bool unite(int a,int b){
        a=find(a); b=find(b);
        if(a==b) return false;
        if(r[a]<r[b]) swap(a,b);
        p[b]=a;
        if(r[a]==r[b]) r[a]++;
        return true;
    }
};

struct Edge {
    int a,b;
    int w;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    if(!(cin >> T)) return 0;
    while(T--){
        int N, M;
        cin >> N >> M;
        vector<Edge> edges;
        edges.reserve(M);
        for(int i=0;i<M;i++){
            int A,B,C;
            cin >> A >> B >> C;
            edges.push_back({A,B,C});
        }
        sort(edges.begin(), edges.end(), [](const Edge& x, const Edge& y){
            return x.w > y.w;
        });
        DSU dsu(N);
        long long total = 0;
        int used = 0;
        for(const auto &e: edges){
            if(dsu.unite(e.a, e.b)){
                total += e.w;
                used++;
                if(used == N-1) break;
            }
        }
        cout << total << "\n";
    }
    return 0;
}
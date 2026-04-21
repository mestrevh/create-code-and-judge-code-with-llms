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
    int find(int x){ return p[x]==x?x:p[x]=find(p[x]); }
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
    
    int N, M;
    if(!(cin >> N >> M)) return 0;
    long long C, R;
    cin >> C >> R;
    vector<tuple<int,int,long long>> edges;
    edges.reserve(M);
    for(int i=0;i<M;i++){
        int U,V;
        long long L;
        cin >> U >> V >> L;
        edges.emplace_back(U,V,L);
    }

    vector<int> parent(N, -1);
    vector<int> distHop(N, -1);
    vector<vector<pair<int,int>>> adj(N);
    vector<vector<int>> adjMST;
    vector<char> inMST(N,0);

    sort(edges.begin(), edges.end(), [](auto &a, auto &b){
        return get<2>(a) < get<2>(b);
    });

    DSU dsu(N);
    long long mstLenSum = 0;
    vector<vector<pair<int,long long>>> mstAdj(N);
    int used = 0;
    for(auto &e: edges){
        int u,v; long long l;
        tie(u,v,l)=e;
        if(dsu.unite(u,v)){
            mstLenSum += l;
            mstAdj[u].push_back({v,l});
            mstAdj[v].push_back({u,l});
            used++;
            if(used==N-1) break;
        }
    }

    long long T1 = mstLenSum * C;

    vector<int> q;
    q.reserve(N);
    distHop[0]=0;
    parent[0]=-1;
    for(int i=0;i<N;i++){
        if(i!=0) distHop[i]=-1;
    }
    for(int i=0;i<N;i++){
        adj[i].clear();
    }

    queue<int> qq;
    qq.push(0);
    while(!qq.empty()){
        int u=qq.front(); qq.pop();
        for(auto [v, w]: mstAdj[u]){
            if(distHop[v]==-1){
                distHop[v]=distHop[u]+1;
                qq.push(v);
            }
        }
    }

    long long T2 = 0;
    for(int i=1;i<N;i++){
        if(distHop[i]>=0) T2 += distHop[i] * R;
    }

    cout << T1 << " " << T2 << "\n";
    return 0;
}
/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

struct DSU {
    int n;
    vector<int> p, sz;
    DSU(int n=0){init(n);}
    void init(int n_) {
        n=n_;
        p.resize(n);
        sz.assign(n,1);
        iota(p.begin(), p.end(), 0);
    }
    int find(int a){ 
        while(p[a]!=a){ p[a]=p[p[a]]; a=p[a]; }
        return a;
    }
    int unite(int a,int b){
        a=find(a); b=find(b);
        if(a==b) return a;
        if(sz[a]<sz[b]) swap(a,b);
        p[b]=a;
        sz[a]+=sz[b];
        return a;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    if(!(cin >> N >> M)) return 0;
    DSU dsu(N);

    vector<pair<int,int>> edges;
    edges.reserve(M);
    for(int i=0;i<M;i++){
        int A,B; cin>>A>>B;
        edges.push_back({A,B});
    }

    int O; 
    cin >> O;

    vector<unordered_set<int>> adj(N);
    for(auto &e: edges){
        int u=e.first, v=e.second;
        u=dsu.find(u); v=dsu.find(v);
        if(u==v) continue;
        adj[u].insert(v);
        adj[v].insert(u);
    }

    vector<int> alive(N,1);
    int aliveCount=N;

    auto mergeSets = [&](int a, int b){
        a = dsu.find(a);
        b = dsu.find(b);
        if(a==b) return a;
        int na = a, nb = b;
        if(adj[na].size() < adj[nb].size()) swap(na, nb);
        int newRoot = dsu.unite(na, nb);
        int big = dsu.find(na);
        int small = (newRoot==big? dsu.find(nb): dsu.find(nb));
        (void)small;

        int rootBig = big;
        int rootSmall = dsu.find( nb );
        if(rootBig != rootSmall){
            int rB = rootBig, rS = rootSmall;
            if(rB==rS) return rB;
        }

        int r1 = dsu.find(na);
        int r2 = dsu.find(nb);
        if(r1==r2) return r1;

        int keep = r1, del = r2;
        if(adj[keep].size() < adj[del].size()) swap(keep, del);

        dsu.unite(keep, del);
        int root = dsu.find(keep);
        int other = dsu.find(del);
        (void)other;

        if(root != keep){
            keep = root;
        }

        auto &bigSet = adj[keep];
        auto &smallSet = adj[del];

        for(int x: smallSet){
            int y = dsu.find(x);
            if(y==keep) continue;
            bigSet.insert(y);
            adj[y].erase(del);
            adj[y].insert(keep);
        }
        smallSet.clear();
        alive[del]=0;
        aliveCount--;
        return keep;
    };

    auto contract_edge = [&](int A, int B){
        if(A==B){
            cout << aliveCount << "\n";
            return;
        }
        int a = dsu.find(A);
        int b = dsu.find(B);
        if(a==b){
            cout << aliveCount << "\n";
            return;
        }

        if(adj[a].size() < adj[b].size()) swap(a,b);
        for(int x: adj[b]){
            int y = dsu.find(x);
            if(y==a) continue;
            adj[a].insert(y);
            adj[y].erase(b);
            adj[y].insert(a);
        }
        adj[b].clear();
        dsu.unite(a,b);
        alive[b]=0;
        aliveCount--;
        cout << aliveCount << "\n";
    };

    auto distance_query = [&](int A, int B)->int{
        int s = dsu.find(A);
        int t = dsu.find(B);
        if(s==t) return 0;

        vector<int> dist(N, -1);
        deque<int> dq;
        dist[s]=0;
        dq.push_back(s);

        while(!dq.empty()){
            int u = dq.front(); dq.pop_front();
            int du = dist[u];
            for(int v: adj[u]){
                v = dsu.find(v);
                if(v==u) continue;
                if(dist[v]==-1){
                    dist[v]=du+1;
                    if(v==t) return dist[v];
                    dq.push_back(v);
                }
            }
        }
        return -1;
    };

    for(int i=0;i<O;i++){
        char type;
        cin >> type;
        int A,B;
        cin >> A >> B;
        if(type=='c'){
            if(A==B){
                cout << aliveCount << "\n";
                continue;
            }
            contract_edge(A,B);
        }else{
            cout << distance_query(A,B) << "\n";
        }
    }

    return 0;
}
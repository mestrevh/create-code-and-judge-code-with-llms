/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int to;
    int rev;
    int cap;
    Edge(int _to=0,int _rev=0,int _cap=0):to(_to),rev(_rev),cap(_cap){}
};

struct Dinic {
    int N;
    vector<vector<Edge>> G;
    vector<int> level, it;
    Dinic(int n=0){ init(n); }
    void init(int n){
        N=n;
        G.assign(N, {});
        level.assign(N, 0);
        it.assign(N, 0);
    }
    void addEdge(int fr,int to,int cap){
        Edge a(to, (int)G[to].size(), cap);
        Edge b(fr, (int)G[fr].size(), 0);
        G[fr].push_back(a);
        G[to].push_back(b);
    }
    bool bfs(int s,int t){
        fill(level.begin(), level.end(), -1);
        queue<int> q;
        level[s]=0;
        q.push(s);
        while(!q.empty()){
            int v=q.front(); q.pop();
            for(const auto &e: G[v]){
                if(e.cap>0 && level[e.to]<0){
                    level[e.to]=level[v]+1;
                    q.push(e.to);
                }
            }
        }
        return level[t]>=0;
    }
    int dfs(int v,int t,int f){
        if(v==t) return f;
        for(int &i=it[v]; i<(int)G[v].size(); i++){
            Edge &e = G[v][i];
            if(e.cap>0 && level[e.to]==level[v]+1){
                int ret=dfs(e.to,t,min(f,e.cap));
                if(ret>0){
                    e.cap-=ret;
                    G[e.to][e.rev].cap+=ret;
                    return ret;
                }
            }
        }
        return 0;
    }
    long long maxflow(int s,int t){
        long long flow=0;
        while(bfs(s,t)){
            fill(it.begin(), it.end(), 0);
            while(true){
                int pushed=dfs(s,t,INT_MAX);
                if(!pushed) break;
                flow += pushed;
            }
        }
        return flow;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    if(!(cin >> n)) return 0;
    int k;
    cin >> k;
    vector<vector<int>> cities(k);
    for(int i=0;i<k;i++){
        vector<int> nodes;
        nodes.reserve(n);
        for(int x=0; x<n; x++){
            if(!(cin)) break;
        }
    }
    vector<int> startNodes(k), endNodes(k);

    vector<int> cityOf(n, -1);
    for(int ci=0; ci<k; ci++){
        string line;
        getline(cin, line);
        if(line.size()==0) { getline(cin, line); }
        while(line.size()==0) getline(cin, line);
        stringstream ss(line);
        int idx=0;
        vector<int> temp;
        while(true){
            int a; 
            if(!(ss >> a)) break;
            temp.push_back(a);
        }
        if(temp.empty()){
            int a;
            while(cin >> a){
                cityOf[a]=ci;
                temp.push_back(a);
                if(cin.peek()=='\n' || cin.peek()==EOF) break;
            }
        }else{
            for(int a: temp) cityOf[a]=ci;
        }
    }

    int m;
    cin >> m;

    struct RawEdge{int u,v,c,d;};
    vector<RawEdge> edges;
    edges.reserve(m);
    for(int i=0;i<m;i++){
        int u,v,c,d;
        cin >> u >> v >> c >> d;
        edges.push_back({u,v,c,d});
    }

    int s,t;
    cin >> s >> t;

    const long long INF = (1LL<<60);
    vector<long long> dist(n, INF);
    dist[s]=0;
    using P=pair<long long,int>;
    priority_queue<P, vector<P>, greater<P>> pq;
    pq.push({0,s});
    while(!pq.empty()){
        auto [cd,v]=pq.top(); pq.pop();
        if(cd!=dist[v]) continue;
        for(const auto &e: edges){
            if(e.u!=v) continue;
        }
    }

    vector<vector<pair<int,int>>> adj(n);
    vector<vector<pair<int,int>>> radj(n);
    for(const auto &e: edges){
        adj[e.u].push_back({e.v, e.d});
        radj[e.v].push_back({e.u, e.d});
    }

    dist.assign(n, INF);
    dist[s]=0;
    pq = priority_queue<P, vector<P>, greater<P>>();
    pq.push({0,s});
    while(!pq.empty()){
        auto [cd,v]=pq.top(); pq.pop();
        if(cd!=dist[v]) continue;
        for(auto [to, w]: adj[v]){
            long long nd = cd + w;
            if(nd < dist[to]){
                dist[to]=nd;
                pq.push({nd,to});
            }
        }
    }

    vector<long long> distT(n, INF);
    distT[t]=0;
    pq = priority_queue<P, vector<P>, greater<P>>();
    pq.push({0,t});
    while(!pq.empty()){
        auto [cd,v]=pq.top(); pq.pop();
        if(cd!=distT[v]) continue;
        for(auto [to, w]: radj[v]){
            long long nd = cd + w;
            if(nd < distT[to]){
                distT[to]=nd;
                pq.push({nd,to});
            }
        }
    }

    long long bestCost = dist[t];

    vector<int> nodes(n);
    iota(nodes.begin(), nodes.end(), 0);
    vector<int> keep;
    keep.reserve(n);
    for(int i=0;i<n;i++){
        if(dist[i]!=INF && distT[i]!=INF && dist[i]+distT[i]==bestCost) keep.push_back(i);
    }

    vector<int> id(n,-1);
    for(int v: keep) id[v]= (int)keep.size(); // will fix
    int cnt=0;
    for(int v: keep) id[v]=cnt++;

    Dinic din(cnt);
    for(const auto &e: edges){
        if(id[e.u]==-1 || id[e.v]==-1) continue;
        if(dist[e.u]!=INF && distT[e.v]!=INF && dist[e.u]+e.d+distT[e.v]==bestCost){
            din.addEdge(id[e.u], id[e.v], e.c);
        }
    }

    long long maxJ = 0;
    if(id[s]!=-1 && id[t]!=-1){
        maxJ = din.maxflow(id[s], id[t]);
    } else {
        maxJ = 0;
    }

    cout << bestCost << "\n" << maxJ << "\n";
    return 0;
}
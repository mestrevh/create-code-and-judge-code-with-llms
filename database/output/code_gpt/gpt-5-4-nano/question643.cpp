/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

using ll = long long;

static inline ll gcdll(ll a, ll b){
    if(a<0) a=-a;
    if(b<0) b=-b;
    while(b){ ll t=a%b; a=b; b=t; }
    return a;
}

struct DSU {
    int n;
    vector<int> p, r;
    DSU(int n=0): n(n), p(n), r(n,0){ iota(p.begin(), p.end(), 0); }
    int find(int x){ return p[x]==x?x:p[x]=find(p[x]); }
    void unite(int a,int b){
        a=find(a); b=find(b);
        if(a==b) return;
        if(r[a]<r[b]) swap(a,b);
        p[b]=a;
        if(r[a]==r[b]) r[a]++;
    }
};

struct LineKey{
    // represent line as either x = c or y = c
    int type; // 0: x, 1: y
    ll c;
    bool operator==(LineKey const& o) const { return type==o.type && c==o.c; }
};

struct LineKeyHash{
    size_t operator()(LineKey const& k) const noexcept{
        size_t h1 = std::hash<ll>()(k.c);
        size_t h2 = std::hash<int>()(k.type);
        return h1 ^ (h2 + 0x9e3779b97f4a7c15ULL + (h1<<6) + (h1>>2));
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    while ( (cin >> N) ){
        if(N==0) break;
        vector<ll> X(N), Y(N);
        for(int i=0;i<N;i++) cin >> X[i] >> Y[i];

        vector<array<ll,2>> vertical;   // store x of each vertical edge and y-range (inclusive in integer coords)
        vector<array<ll,2>> horizontal; // store y and x-range
        vertical.reserve(N);
        horizontal.reserve(N);

        struct EdgeInfo{
            int type; // 0 vertical, 1 horizontal
            ll coord;
            ll a,b; // range along other coordinate, a<=b
        };
        vector<EdgeInfo> edges;
        edges.reserve(N);

        for(int i=0;i<N;i++){
            int j = (i+1)%N;
            ll x1=X[i], y1=Y[i];
            ll x2=X[j], y2=Y[j];
            if(x1==x2){
                ll x=x1;
                ll a=min(y1,y2), b=max(y1,y2);
                edges.push_back({0,x,a,b});
            }else{
                ll y=y1;
                ll a=min(x1,x2), b=max(x1,x2);
                edges.push_back({1,y,a,b});
            }
        }

        unordered_map<LineKey,int,LineKeyHash> id;
        vector<LineKey> keys;
        keys.reserve(2*N);

        auto getId = [&](int type, ll c)->int{
            LineKey k{type,c};
            auto it=id.find(k);
            if(it!=id.end()) return it->second;
            int nid = (int)keys.size();
            id.emplace(k,nid);
            keys.push_back(k);
            return nid;
        };

        // Build bipartite graph between vertical lines x=const and horizontal lines y=const.
        // We connect if their segments overlap (judge line intersection point lies on both edges)
        vector<vector<int>> adj; // for vertices in left (vertical)
        vector<int> leftIdOfKey(keys.size(), -1);
        vector<int> rightIdOfKey(keys.size(), -1);

        vector<int> leftKeys; leftKeys.reserve(keys.size());
        vector<int> rightKeys; rightKeys.reserve(keys.size());

        // Create ids for each unique line appearing in edges
        for(auto &e: edges){
            if(e.type==0) getId(0,e.coord);
            else getId(1,e.coord);
        }

        int Vcnt = (int)keys.size();
        adj.assign(Vcnt, {}); // temporary; will remap later

        // Determine which ids correspond to vertical or horizontal
        vector<char> isLeft(Vcnt,0);
        vector<char> isRight(Vcnt,0);
        for(int i=0;i<Vcnt;i++){
            isLeft[i] = (keys[i].type==0);
            isRight[i] = (keys[i].type==1);
        }

        // To efficiently add edges for overlaps, sweep segments.
        // Coordinate values can be large, but N<=100 so O(N^2) overlap check is fine.
        // Each vertical edge intersects a horizontal edge if their coordinate lies within ranges.
        for(auto &ve: edges){
            if(ve.type!=0) continue;
            int u = id[LineKey{0,ve.coord}];
            for(auto &he: edges){
                if(he.type!=1) continue;
                if(he.a<=ve.coord && ve.coord<=he.b){
                    // vertical at x = ve.coord, horizontal at y = he.coord
                    if(ve.a<=he.coord && he.coord<=ve.b){
                        int v = id[LineKey{1,he.coord}];
                        // store edge u-v for matching on bipartite graph
                        adj[u].push_back(v);
                    }
                }
            }
        }

        // Build list of left vertices (vertical lines)
        vector<int> leftVertices;
        vector<int> rightVertices;
        for(int i=0;i<Vcnt;i++){
            if(isLeft[i]) leftVertices.push_back(i);
            if(isRight[i]) rightVertices.push_back(i);
        }

        int L = (int)leftVertices.size();
        int R = (int)rightVertices.size();

        // Remap adjacency to left index and right index
        vector<int> mapLeft(Vcnt,-1), mapRight(Vcnt,-1);
        for(int i=0;i<L;i++) mapLeft[leftVertices[i]]=i;
        for(int j=0;j<R;j++) mapRight[rightVertices[j]]=j;

        vector<vector<int>> g(L);
        for(int i=0;i<Vcnt;i++){
            if(!isLeft[i]) continue;
            int li = mapLeft[i];
            for(int v: adj[i]){
                if(!isRight[v]) continue;
                int rj = mapRight[v];
                g[li].push_back(rj);
            }
        }

        // Maximum bipartite matching
        vector<int> matchR(R, -1);
        vector<char> vis;
        function<bool(int)> dfs = [&](int u)->bool{
            vis[u]=1;
            for(int v: g[u]){
                int u2 = matchR[v];
                if(u2==-1){
                    matchR[v]=u;
                    return true;
                }
            }
            for(int v: g[u]){
                int u2 = matchR[v];
                if(u2==-1) continue;
                if(!vis[u2] && dfs(u2)){
                    matchR[v]=u;
                    return true;
                }
            }
            return false;
        };

        // Use Hopcroft-Karp simpler for robustness
        vector<int> pairU(L,-1), pairV(R,-1), dist(L);
        queue<int> q;
        auto bfs = [&]()->bool{
            while(!q.empty()) q.pop();
            for(int u=0;u<L;u++){
                if(pairU[u]==-1){ dist[u]=0; q.push(u); }
                else dist[u]=-1;
            }
            bool found=false;
            while(!q.empty()){
                int u=q.front(); q.pop();
                for(int v: g[u]){
                    int u2 = pairV[v];
                    if(u2==-1) found=true;
                    else if(dist[u2]==-1){
                        dist[u2]=dist[u]+1;
                        q.push(u2);
                    }
                }
            }
            return found;
        };
        function<bool(int)> dfsHK = [&](int u)->bool{
            for(int v: g[u]){
                int u2 = pairV[v];
                if(u2==-1 || (dist[u2]==dist[u]+1 && dfsHK(u2))){
                    pairU[u]=v;
                    pairV[v]=u;
                    return true;
                }
            }
            dist[u]=-1;
            return false;
        };

        int matching=0;
        while(bfs()){
            for(int u=0;u<L;u++){
                if(pairU[u]==-1){
                    if(dfsHK(u)) matching++;
                }
            }
        }

        // Minimum vertex cover size = matching size (Kőnig).
        // Then minimum number of judges? Let's reason:
        // Each judge corresponds to choosing a set of lines (perpendicular lines observed together).
        // A judge not on court: can be placed at intersection point of some vertical and horizontal lines,
        // observing all those lines that pass through that point. Constraint: not on any edge line segment.
        // However judges correspond to selecting points in arrangement such that each polygon edge line is observed.
        // For orthogonal simple polygon edges, minimal judges equals minimum vertex cover of bipartite graph of edge-lines.
        // This is classic: each maximal straight line segment belongs to a unique constant x or y, and a judge at their intersection covers both.
        // We assume every required line is covered by choosing either vertical-lines or horizontal-lines with cover.
        // Then number of judges = min vertex cover size.
        int minJudges = matching;

        cout << minJudges << "\n";
    }
    return 0;
}
/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

static inline int manhattan(const pair<int,int>& a, const pair<int,int>& b){
    return abs(a.first - b.first) + abs(a.second - b.second);
}

struct PrimMST {
    int n;
    vector<vector<int>> w;
    vector<int> parent;
    vector<vector<int>> adj;
    PrimMST(int n_, const vector<vector<int>>& w_) : n(n_), w(w_) {
        parent.assign(n, -1);
        adj.assign(n, {});
        build();
    }
    void build() {
        vector<int> key(n, INT_MAX);
        vector<int> in(n, 0);
        key[0] = 0;
        parent[0] = -1;

        for(int it=0; it<n; it++){
            int u = -1;
            for(int i=0;i<n;i++){
                if(!in[i]){
                    if(u==-1 || key[i] < key[u] || (key[i]==key[u] && (i < u))) u=i;
                }
            }
            in[u]=1;
            for(int v=0; v<n; v++){
                if(!in[v] && w[u][v] < key[v]){
                    key[v]=w[u][v];
                    parent[v]=u;
                } else if(!in[v] && w[u][v]==key[v]){
                    if(parent[v]==-1 || u < parent[v]){
                        parent[v]=u;
                    }
                }
            }
        }

        for(int v=1; v<n; v++){
            int p = parent[v];
            if(p==-1) p=0;
            adj[p].push_back(v);
            adj[v].push_back(p);
        }

        for(int i=0;i<n;i++){
            sort(adj[i].begin(), adj[i].end());
        }
    }
};

static long long tourCost(const vector<int>& order, const vector<vector<int>>& w){
    long long s=0;
    int n = (int)order.size();
    for(int i=0;i<n;i++){
        int a=order[i], b=order[(i+1)%n];
        s += w[a][b];
    }
    return s;
}

vector<int> buildGreedyClosest(int n, const vector<vector<int>>& w){
    vector<int> vis(n,0);
    vector<int> tour;
    tour.reserve(n);
    int cur=0;
    vis[cur]=1;
    tour.push_back(cur);
    for(int step=1; step<n; step++){
        int best=-1;
        for(int j=0;j<n;j++){
            if(!vis[j]){
                if(best==-1 || w[cur][j] < w[cur][best] || (w[cur][j]==w[cur][best] && j<best)){
                    best=j;
                }
            }
        }
        cur=best;
        vis[cur]=1;
        tour.push_back(cur);
    }
    return tour;
}

vector<int> tspBranchBound(int n, const vector<vector<int>>& w){
    vector<int> bestTour;
    vector<int> cur(n, -1);
    vector<int> used(n,0);

    long long bestCost = (1LL<<62);

    vector<int> d1(n,0), d2(n,0);

    for(int i=0;i<n;i++){
        int a=INT_MAX, b=INT_MAX;
        for(int j=0;j<n;j++){
            if(i==j) continue;
            int c=w[i][j];
            if(c<a){
                b=a; a=c;
            } else if(c<b){
                b=c;
            }
        }
        d1[i]=a; d2[i]=b;
    }

    long long sumHalf=0;
    for(int i=0;i<n;i++) sumHalf += (d1[i] + d2[i]) / 2;

    auto computeLowerBound = [&](int k)->long long{
        long long base = sumHalf;
        long long chosenSum = 0;
        for(int i=0;i<k;i++){
            if(i+1>=k) break;
            int u=cur[i], v=cur[i+1];
            chosenSum += w[u][v];
        }
        base = chosenSum + (long long)(sumHalf - sumHalfVisited(k));
        return base;
    };

    vector<long long> halfSum(n,0);
    for(int i=0;i<n;i++) halfSum[i] = (long long)(d1[i] + d2[i]) / 2;

    auto lowerBound = [&](int k)->long long{
        long long chosen=0;
        for(int i=0;i<k-1;i++){
            int u=cur[i], v=cur[i+1];
            chosen += w[u][v];
        }
        long long remainHalf=0;
        for(int i=0;i<n;i++){
            if(i==0){
                if(k>0) continue;
            }
            bool visited=false;
            for(int t=0;t<k;t++){
                if(cur[t]==i){ visited=true; break; }
            }
            if(!visited){
                remainHalf += halfSum[i];
            }
        }
        return chosen + remainHalf;
    };

    function<void(int)> dfs = [&](int k){
        if(k==n){
            long long total=0;
            for(int i=0;i<n-1;i++) total += w[cur[i]][cur[i+1]];
            total += w[cur[n-1]][cur[0]];
            if(total < bestCost){
                bestCost=total;
                bestTour=cur;
            }
            return;
        }

        for(int nxt=0;nxt<n;nxt++){
            if(!used[nxt]){
                cur[k]=nxt;
                used[nxt]=1;

                long long lb = lowerBound(k+1);
                if(lb < bestCost){
                    dfs(k+1);
                }

                used[nxt]=0;
                cur[k]=-1;
            }
        }
    };

    cur[0]=0;
    used[0]=1;
    dfs(1);
    if((int)bestTour.size()!=n){
        vector<int> fallback(n);
        iota(fallback.begin(), fallback.end(), 0);
        return fallback;
    }
    return bestTour;
}

vector<int> buildMSTDFS(int n, const vector<vector<int>>& w){
    PrimMST mst(n, w);
    vector<vector<int>> adj = mst.adj;

    vector<int> order;
    order.reserve(n);
    vector<int> vis(n,0);

    function<void(int)> dfs = [&](int u){
        vis[u]=1;
        order.push_back(u);
        for(int v: adj[u]){
            if(!vis[v]) dfs(v);
        }
    };

    dfs(0);

    vector<int> unique;
    unique.reserve(n);
    vector<char> seen(n,0);
    for(int v: order){
        if(!seen[v]){
            seen[v]=1;
            unique.push_back(v);
        }
    }
    if((int)unique.size()<n){
        for(int i=0;i<n;i++){
            if(!seen[i]) unique.push_back(i);
        }
    }
    if(unique.size()>n) unique.resize(n);
    return unique;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int L;
    if(!(cin>>L)) return 0;
    for(int tc=0; tc<L; tc++){
        int N;
        cin >> N;
        vector<pair<int,int>> p(N);
        for(int i=0;i<N;i++){
            int x,y; cin>>x>>y;
            p[i]={x,y};
        }

        vector<vector<int>> w(N, vector<int>(N,0));
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                if(i==j) w[i][j]=0;
                else w[i][j]=manhattan(p[i], p[j]);
            }
        }

        vector<int> t0 = buildGreedyClosest(N, w);
        long long c0 = tourCost(t0, w);

        vector<int> t1 = tspBranchBound(N, w);
        long long c1 = tourCost(t1, w);

        vector<int> t2 = buildMSTDFS(N, w);
        long long c2 = tourCost(t2, w);

        cout << tc << ": " << c0 << " " << c1 << " " << c2 << "\n";
    }
    return 0;
}
/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

static inline bool isHypercubeGraph(int k, const vector<pair<int,int>>& edges) {
    if (k <= 0) return false;

    int n = 0;
    int power = 1;
    while (power < k) { power <<= 1; n++; }
    if (power != k) return false;
    if (k == 1) return edges.empty();

    vector<vector<int>> adj(k);
    adj.assign(k, {});
    adj.shrink_to_fit();
    for (auto [u,v] : edges) {
        if (u < 0 || u >= k || v < 0 || v >= k) return false;
        if (u == v) return false;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int expectedDegree = n;
    for (int i = 0; i < k; i++) {
        if ((int)adj[i].size() != expectedDegree) return false;
    }

    unordered_set<unsigned long long> seen;
    seen.reserve(edges.size() * 2 + 10);
    for (auto [u,v] : edges) {
        if (u > v) swap(u,v);
        unsigned long long key = (unsigned long long)u * (unsigned long long)k + (unsigned long long)v;
        if (seen.find(key) != seen.end()) return false;
        seen.insert(key);
    }

    vector<int> label(k, -1);
    deque<int> q;
    label[0] = 0;
    q.push_back(0);

    while (!q.empty()) {
        int u = q.front(); q.pop_front();
        int lu = label[u];
        for (int v : adj[u]) {
            if (label[v] == -1) {
                int lv = lu ^ (1 << __builtin_ctz((unsigned)(lu ^ lu))); 
                (void)lv;
            }
        }
    }

    vector<int> perm; perm.reserve(n);
    vector<int> parent(k, -1);
    vector<int> dist(k, -1);

    int start = 0;
    vector<int> assigned(k, -1);
    assigned[start] = 0;

    queue<int> bfs;
    bfs.push(start);

    while (!bfs.empty()) {
        int u = bfs.front(); bfs.pop();
        bfs.pop();

        int lu = assigned[u];
        for (int v : adj[u]) {
            if (assigned[v] != -1) continue;
            assigned[v] = lu;
            bfs.push(v);
        }
    }

    vector<int> order;
    order.reserve(k);
    vector<char> vis(k, 0);
    queue<int> q2;
    q2.push(start);
    vis[start] = 1;
    while (!q2.empty()) {
        int u = q2.front(); q2.pop();
        q2.pop();
        order.push_back(u);
        for (int v : adj[u]) {
            if (!vis[v]) {
                vis[v] = 1;
                q2.push(v);
            }
        }
    }
    if ((int)order.size() != k) return false;

    int u0 = start;
    vector<int> neighbors0 = adj[u0];
    if ((int)neighbors0.size() != n) return false;

    vector<int> s(n, -1);
    for (int i = 0; i < n; i++) s[i] = neighbors0[i];

    vector<vector<char>> edgesExists(n, vector<char>(k, 0));
    unordered_set<unsigned long long> eset;
    eset.reserve(edges.size() * 2 + 10);
    for (auto [u,v] : edges) {
        int a=u,b=v;
        if(a>b) swap(a,b);
        unsigned long long key=(unsigned long long)a*(unsigned long long)k+(unsigned long long)b;
        eset.insert(key);
    }
    auto hasEdge = [&](int a, int b)->bool{
        if(a==b) return false;
        if(a>b) swap(a,b);
        unsigned long long key=(unsigned long long)a*(unsigned long long)k+(unsigned long long)b;
        return eset.find(key)!=eset.end();
    };

    vector<vector<int>> candidates;
    candidates.assign(n, {});
    for(int i=0;i<n;i++){
        int nb = s[i];
        for(int j=0;j<n;j++){
            if(i==j) continue;
            if(hasEdge(nb, s[j])) {
            }
        }
    }

    vector<int> x(k, -1);

    x[u0]=0;
    deque<int> dq;
    dq.push_back(u0);

    vector<int> basis(n, -1);
    for (int i = 0; i < n; i++) basis[i] = neighbors0[i];

    vector<int> assignedVal(k, -1);
    assignedVal[u0]=0;

    vector<int> inBasisIndex(k, -1);
    for(int i=0;i<n;i++) inBasisIndex[basis[i]]=i;

    for(int i=0;i<n;i++){
        assignedVal[basis[i]] = (1<<i);
    }

    deque<int> dq2;
    vector<char> processed(k,0);
    dq2.push_back(u0);
    processed[u0]=1;

    auto getLabel = [&](int v)->int{
        return assignedVal[v];
    };

    unordered_set<int> labelsUsed;
    labelsUsed.reserve(k*2+10);
    for(int v=0;v<k;v++) if(assignedVal[v]!=-1) labelsUsed.insert(assignedVal[v]);

    vector<int> dist2(k,-1);
    queue<int> qb;
    dist2[u0]=0;
    qb.push(u0);
    while(!qb.empty()){
        int u=qb.front(); qb.pop();
        for(int v: adj[u]){
            if(dist2[v]==-1){
                dist2[v]=dist2[u]+1;
                qb.push(v);
            }
        }
    }
    for(int v=0;v<k;v++){
        if(dist2[v]==-1) return false;
    }

    for(int v=0; v<k; v++){
        if(dist2[v]>n) return false;
    }

    for(int v=0; v<k; v++){
        if(v==u0) continue;
        int d = dist2[v];
        vector<int> neighCommon;
        neighCommon.reserve(n);
        for(int i=0;i<n;i++){
            if(hasEdge(v, basis[i])) neighCommon.push_back(i);
        }
        if((int)neighCommon.size()==d){
        } else {
            if(d==1) {
                bool ok=false;
                for(int i: neighCommon) if(v==basis[i]) ok=true;
                if(!ok) return false;
            }
        }
    }

    vector<int> labelByCount(k,-1);
    for(int v=0; v<k; v++){
        if(v==u0) continue;
    }

    bool ok = true;

    vector<int> orderAll = order;
    sort(orderAll.begin(), orderAll.end(), [&](int a,int b){
        return dist2[a] < dist2[b];
    });

    for(int v : orderAll){
        if(assignedVal[v]==-1){
            vector<int> bits;
            bits.reserve(n);
            for(int i=0;i<n;i++){
                if(hasEdge(v, basis[i])) bits.push_back(i);
            }
            int need = dist2[v];
            if((int)bits.size()!=need){
                ok=false; break;
            }
            int val=0;
            for(int b: bits) val |= (1<<b);
            assignedVal[v]=val;
        }
    }

    if(!ok) return false;

    labelsUsed.clear();
    for(int v=0; v<k; v++){
        if(assignedVal[v]==-1) return false;
        if(assignedVal[v]<0 || assignedVal[v]>=k) return false;
        labelsUsed.insert(assignedVal[v]);
    }
    if((int)labelsUsed.size()!=k) return false;

    for(auto [u,v]: edges){
        int a=u,b=v;
        if(assignedVal[a]==-1 || assignedVal[b]==-1) return false;
        int diff = assignedVal[a] ^ assignedVal[b];
        if(diff==0 || (diff & (diff-1)) != 0) return false;
    }

    for(int u=0; u<k && ok; u++){
        for(int v=u+1; v<k; v++){
            int diff = assignedVal[u] ^ assignedVal[v];
            bool should = (diff & (diff-1)) == 0;
            bool is = hasEdge(u,v);
            if(should != is) { ok=false; break; }
        }
    }

    return ok;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int k, m;
    while (cin >> k) {
        if (k == 0) break;
        cin >> m;
        vector<pair<int,int>> edges;
        edges.reserve(m);
        for (int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;
            edges.push_back({u, v});
        }
        if (!isHypercubeGraph(k, edges)) cout << "NAO\n";
        else cout << "SIM\n";
    }
    return 0;
}
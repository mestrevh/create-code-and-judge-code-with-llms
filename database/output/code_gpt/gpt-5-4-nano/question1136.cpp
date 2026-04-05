/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

struct SegTree {
    int n;
    vector<int> tmax;          // max value
    vector<unsigned char> lazy; // 0/1: pending assignment (set to v)
    vector<int> lazyVal;
    SegTree() : n(0) {}
    SegTree(int n_) { init(n_); }
    void init(int n_) {
        n = n_;
        tmax.assign(4*n+5, 0);
        lazy.assign(4*n+5, 0);
        lazyVal.assign(4*n+5, 0);
    }
    void apply(int v, int val) {
        tmax[v] = val;
        lazy[v] = 1;
        lazyVal[v] = val;
    }
    void push(int v) {
        if(lazy[v]) {
            apply(v*2, lazyVal[v]);
            apply(v*2+1, lazyVal[v]);
            lazy[v] = 0;
        }
    }
    void build(int v, int l, int r, const vector<int>& a) {
        if(l==r) { tmax[v] = a[l]; return; }
        int m=(l+r)>>1;
        build(v*2,l,m,a);
        build(v*2+1,m+1,r,a);
        tmax[v]=max(tmax[v*2], tmax[v*2+1]);
    }
    void build(const vector<int>& a) {
        build(1,1,n,a);
    }
    void rangeAssign(int v, int l, int r, int ql, int qr, int val){
        if(ql>r||qr<l) return;
        if(ql<=l && r<=qr){ apply(v,val); return; }
        push(v);
        int m=(l+r)>>1;
        rangeAssign(v*2,l,m,ql,qr,val);
        rangeAssign(v*2+1,m+1,r,ql,qr,val);
        tmax[v]=max(tmax[v*2], tmax[v*2+1]);
    }
    void rangeAssign(int l,int r,int val){
        if(l>r) return;
        rangeAssign(1,1,n,l,r,val);
    }
    int getMax() const { return tmax[1]; }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, Q;
    if(!(cin >> N >> Q)) return 0;
    vector<int> p(N+1);
    for(int i=1;i<=N;i++) cin >> p[i];

    vector<int> indeg(N+1,0);
    for(int i=1;i<=N;i++) indeg[p[i]]++;

    queue<int> qu;
    vector<char> inCycle(N+1,1);
    for(int i=1;i<=N;i++){
        if(indeg[i]==0){
            qu.push(i);
            inCycle[i]=0;
        }
    }
    while(!qu.empty()){
        int u=qu.front(); qu.pop();
        int v=p[u];
        indeg[v]--;
        if(indeg[v]==0){
            inCycle[v]=0;
            qu.push(v);
        }
    }

    vector<int> cycleId(N+1,-1);
    int cid=0;
    vector<int> cycNodes;
    vector<int> state(N+1,0);
    vector<int> posInCycle(N+1,0);
    for(int i=1;i<=N;i++){
        if(inCycle[i] && cycleId[i]==-1){
            int u=i;
            while(cycleId[u]==-1){
                cycleId[u]=cid;
                u=p[u];
            }
            cid++;
        }
    }

    vector<vector<int>> cycles(cid);
    for(int i=1;i<=N;i++){
        if(inCycle[i]) cycles[cycleId[i]].push_back(i);
    }

    for(int c=0;c<cid;c++){
        for(int x: cycles[c]) posInCycle[x]= -1;
        int start = cycles[c][0];
        int cur = start;
        int idx=0;
        do{
            posInCycle[cur]=idx++;
            cur=p[cur];
        } while(cur!=start);
    }

    vector<int> dist(N+1,0);
    vector<int> rootCycle(N+1,-1);
    vector<int> rootPos(N+1,0);

    queue<int> q2;
    for(int i=1;i<=N;i++){
        if(inCycle[i]){
            rootCycle[i]=i;
            rootPos[i]=posInCycle[i];
            dist[i]=0;
            q2.push(i);
        }
    }

    vector<vector<int>> rev(N+1);
    for(int i=1;i<=N;i++) rev[p[i]].push_back(i);

    while(!q2.empty()){
        int u=q2.front(); q2.pop();
        int rc = rootCycle[u];
        int rpos = rootPos[u];
        for(int v: rev[u]){
            if(inCycle[v]) continue;
            rootCycle[v]=rc;
            rootPos[v]=rpos;
            dist[v]=dist[u]+1;
            q2.push(v);
        }
    }

    auto findStepsToExit = [&](int start, int X)->bool{
        // returns true if reaches <= X at some time
        // but for our approach we need exact step to first <=X? not used.
        return false;
    };

    // For each start s, compute its first time it visits a node <= X depends on X, so can't precompute.
    // Alternative: represent process as deterministic. Game ends iff there exists t>=0 with f^t(s) <= X.
    // For given s, the set of nodes reachable is all nodes in its functional component.
    // For nodes on path, f^t(s) strictly decreases? no.
    // However to compare probabilities we only need count of starting positions whose trajectory hits <=X.
    // Equivalent to: for each s, define M[s] = minimal node index encountered along its trajectory (including in cycle).
    // Because if minimal encountered is m, then trajectory will hit some node <= X iff m <= X.
    // True: if minimal encountered index m <= X, then the node achieving m is <=X and visited; conversely if all visited nodes > X then minimal > X.
    // So define M[s] as minimum over all nodes in reachable set from s (component).
    vector<int> M(N+1, N+1);
    // Compute minima for cyclic components
    for(int c=0;c<cid;c++){
        int mn = INT_MAX;
        for(int x: cycles[c]) mn = min(mn, x);
        for(int x: cycles[c]) M[x]=mn;
    }
    // Propagate minima backwards along trees into cycle
    // Need nodes not in cycles in topological order from cycle outward? Use reverse edges and BFS from cycle nodes.
    queue<int> q3;
    vector<char> vis(N+1,0);
    for(int i=1;i<=N;i++){
        if(inCycle[i]){
            vis[i]=1;
            q3.push(i);
        }
    }
    while(!q3.empty()){
        int u=q3.front(); q3.pop();
        for(int v: rev[u]){
            if(vis[v]) continue;
            vis[v]=1;
            M[v]=M[u];
            q3.push(v);
        }
    }

    // Now for interval [L,R], starting positions uniform. Game terminates iff M[s] <= X.
    // Probability terminate = count(M[s] <= X)/len.
    // Not terminate = 1 - that. Need X making probabilities as close as possible:
    // minimize |p_term - p_nonterm| = |2*count/len - 1|, equivalently minimize |count - len/2|.
    // If tie, choose smallest X closest to start of queue: "mais próximo do início da fila" -> smallest X? start refers to position 1,
    // so "X mais próximo do início da fila" means minimal X among best.
    // So for a given interval length len and counts as function of X (nondecreasing stepwise),
    // we need X that yields count closest to len/2; in ties minimal X.
    // Since counts change only at values M[s]. Let freq of minima values in interval.
    // We can find candidate X values as those thresholds where count equals some k (k closest to len/2).
    // Let target counts: k1 = floor(len/2), k2=k1 (or ceil). Closest to len/2:
    // For integer count c, minimize |c - len/2|. For len even -> unique c=len/2.
    // For len odd -> two closest c=(len/2 floor) and c=(len/2 ceil); tie -> choose smaller X among resulting thresholds.
    // Need smallest X such that count>=c? Actually count(M<=X).
    // For a desired count c, minimal X achieving count>=c corresponds to X being the c-th order statistic of M in interval.
    // But if len odd and both c0 and c1 equally close, choose smaller X; c0 < c1 => smaller order statistic => smaller X, so choose c0 (floor).
    // Therefore optimal count = floor(len/2) if len odd else len/2.
    // However if best count is floor and ceil tie, choose smaller X which corresponds to smaller count threshold; that is floor(len/2).
    // For len even only one. Great.
    // Thus X* is the value of the element at position k = floor(len/2) (0-index?) in sorted M, with 1-indexed count threshold.
    // Specifically, let sorted minima values a1<=a2<=...<=alen.
    // count(M<=X) = maximal i with ai<=X.
    // To get count = k where k=floor(len/2), minimal X with count>=k is ak.
    // But could choose smaller X giving count < k with same distance? For even len: distance min at c=len/2 exactly; so must have count=len/2.
    // For odd len: distances: |k - len/2| = |k - (2k+1)/2| = 0.5 for k=floor, and similarly for k+1. Choosing smaller X implies smaller count (k), so count=k.
    // Hence choose X=ak.
    // If k=0 (len=1) but len>=2 => ok. For len=2 => k=1.
    int maxVal = N;
    // Need order statistic queries on M over ranges [L,R].
    // Use offline with BIT over values while processing k-th element via parallel binary search? But Q up to 1e5, N 5e4.
    // We can use Fenwick with value positions and do selection using BIT with persistent segment tree.
    // Since values M are between 1..N. We'll build wavelet tree or persistent segtree for k-th.
    vector<int> vals(N+1);
    for(int i=1;i<=N;i++) vals[i]=M[i];

    struct PST {
        int n, V;
        vector<int> leftc, rightc, sum;
        int nodes;
        vector<int> roots;
        PST(int n_, int V_): n(n_), V(V_) {
            int maxNodes = (n_+5) * 20;
            leftc.assign(maxNodes,0);
            rightc.assign(maxNodes,0);
            sum.assign(maxNodes,0);
            nodes=1;
            roots.assign(n_+1,0);
        }
        int cloneNode(int from){
            int id = nodes++;
            leftc[id]=leftc[from];
            rightc[id]=rightc[from];
            sum[id]=sum[from];
            return id;
        }
        int update(int prev, int l, int r, int pos){
            int cur = cloneNode(prev);
            sum[cur]++;
            if(l!=r){
                int m=(l+r)>>1;
                if(pos<=m) {
                    leftc[cur]=update(leftc[prev], l, m, pos);
                } else {
                    rightc[cur]=update(rightc[prev], m+1, r, pos);
                }
            }
            return cur;
        }
        void buildRoots(const vector<int>& a){
            roots[0]=0;
            for(int i=1;i<=n;i++){
                roots[i]=update(roots[i-1],1,V,a[i]);
            }
        }
        int kth(int u, int v, int l, int r, int k){
            if(l==r) return l;
            int m=(l+r)>>1;
            int cntLeft = sum[leftc[v]] - sum[leftc[u]];
            if(k<=cntLeft) return kth(leftc[u], leftc[v], l, m, k);
            return kth(rightc[u], rightc[v], m+1, r, k-cntLeft);
        }
    };

    PST pst(N, N);
    pst.buildRoots(vals);

    for(int qi=0;qi<Q;qi++){
        int L,R; cin >> L >> R;
        int len = R-L+1;
        int k = len/2; // floor, 1-indexed order statistic position
        // k in [1..len-1] since len>=2
        int ans = pst.kth(pst.roots[L-1], pst.roots[R], 1, N, k);
        cout << ans << "\n";
    }
    return 0;
}
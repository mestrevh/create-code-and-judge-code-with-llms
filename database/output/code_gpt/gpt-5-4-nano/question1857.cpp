/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

struct SegTree {
    struct Node {
        uint64_t cnt0[31], cnt1[31];
        uint64_t sum;
        Node() : sum(0) { memset(cnt0, 0, sizeof(cnt0)); memset(cnt1, 0, sizeof(cnt1)); }
    };
    int n;
    vector<Node> st;
    vector<int> lenL, lenR;

    SegTree(int n_=0){ init(n_); }
    void init(int n_) {
        n = n_;
        st.assign(4*n+5, Node());
    }

    static inline void addValue(Node &nd, uint32_t val) {
        nd.sum += val;
        for(int b=0;b<31;b++){
            if((val>>b)&1ULL) nd.cnt1[b]++; else nd.cnt0[b]++;
        }
    }

    static inline Node mergeNode(const Node &a, const Node &b){
        Node c;
        c.sum = a.sum + b.sum;
        for(int i=0;i<31;i++){
            c.cnt0[i] = a.cnt0[i] + b.cnt0[i];
            c.cnt1[i] = a.cnt1[i] + b.cnt1[i];
        }
        return c;
    }

    void build(const vector<uint32_t> &arr, int p, int l, int r){
        if(l==r){
            addValue(st[p], arr[l]);
            return;
        }
        int m=(l+r)>>1;
        build(arr,p<<1,l,m);
        build(arr,p<<1|1,m+1,r);
        st[p]=mergeNode(st[p<<1], st[p<<1|1]);
    }

    void applyXor(int p, uint32_t k){
        for(int b=0;b<31;b++){
            if((k>>b)&1U){
                uint64_t c0 = st[p].cnt0[b];
                uint64_t c1 = st[p].cnt1[b];
                st[p].cnt0[b] = c1;
                st[p].cnt1[b] = c0;
                st[p].sum += ((c0 - c1) << b);
            }
        }
    }

    void updateXor(int p, int l, int r, int ql, int qr, uint32_t k){
        if(ql>r || qr<l) return;
        if(ql<=l && r<=qr){
            applyXor(p,k);
            lazy[p] ^= k;
            return;
        }
        push(p);
        int m=(l+r)>>1;
        updateXor(p<<1,l,m,ql,qr,k);
        updateXor(p<<1|1,m+1,r,ql,qr,k);
        st[p]=mergeNode(st[p<<1], st[p<<1|1]);
    }

    void querySum(int p, int l, int r, int ql, int qr, uint64_t &res){
        if(ql>r || qr<l) return;
        if(ql<=l && r<=qr){
            res += st[p].sum;
            return;
        }
        push(p);
        int m=(l+r)>>1;
        querySum(p<<1,l,m,ql,qr,res);
        querySum(p<<1|1,m+1,r,ql,qr,res);
    }

    vector<uint32_t> lazy;
    void initLazy(){
        lazy.assign(4*n+5, 0);
    }

    inline void push(int p){
        uint32_t k = lazy[p];
        if(k){
            applyXor(p<<1,k);
            lazy[p<<1] ^= k;
            applyXor(p<<1|1,k);
            lazy[p<<1|1] ^= k;
            lazy[p]=0;
        }
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    if(!(cin>>n)) return 0;
    vector<vector<int>> g(n+1);
    for(int i=0;i<n-1;i++){
        int x,y; cin>>x>>y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    vector<uint32_t> val(n+1);
    for(int i=1;i<=n;i++){
        uint64_t t; cin>>t;
        val[i]=(uint32_t)t;
    }

    vector<int> parent(n+1,-1), tin(n+1), tout(n+1), order;
    order.reserve(n);
    int timer=0;
    vector<int> st;
    st.reserve(n);
    vector<int> it(n+1,0);
    st.push_back(1);
    parent[1]=0;
    while(!st.empty()){
        int v = st.back();
        if(it[v]==0){
            tin[v]=timer++;
            order.push_back(v);
        }
        if(it[v] < (int)g[v].size()){
            int to=g[v][it[v]++];
            if(to==parent[v]) continue;
            parent[to]=v;
            st.push_back(to);
        }else{
            tout[v]=timer-1;
            st.pop_back();
        }
    }

    vector<uint32_t> arr(n);
    for(int i=0;i<n;i++){
        arr[i]=val[order[i]];
    }

    SegTree seg(n);
    seg.build(arr,1,0,n-1);
    seg.initLazy();

    int q; cin>>q;
    while(q--){
        int type; cin>>type;
        if(type==1){
            int V; uint32_t K;
            cin>>V>>K;
            int l = tin[V], r = tout[V];
            seg.updateXor(1,0,n-1,l,r,K);
        }else{
            int V; cin>>V;
            int l = tin[V], r = tout[V];
            uint64_t res=0;
            seg.querySum(1,0,n-1,l,r,res);
            cout<<res<<"\n";
        }
    }
    return 0;
}
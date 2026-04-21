/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

struct Node {
    long long sum;
    int mn;
    Node(long long s=0, int m=INT_MAX): sum(s), mn(m) {}
};

struct SegTree {
    int n;
    vector<Node> st;

    SegTree(int n_=0){ init(n_); }

    void init(int n_){
        n = n_;
        st.assign(4*n+5, Node());
    }

    static Node merge(const Node& a, const Node& b){
        return Node(a.sum + b.sum, min(a.mn, b.mn));
    }

    void build(const vector<int>& a, int p, int l, int r){
        if(l==r){
            st[p] = Node(a[l], a[l]);
            return;
        }
        int m=(l+r)>>1;
        build(a, p<<1, l, m);
        build(a, p<<1|1, m+1, r);
        st[p] = merge(st[p<<1], st[p<<1|1]);
    }

    void build(const vector<int>& a){
        init((int)a.size());
        if(n>0) build(a,1,0,n-1);
    }

    void update(int idx, int val, int p, int l, int r){
        if(l==r){
            st[p].sum = val;
            st[p].mn = val;
            return;
        }
        int m=(l+r)>>1;
        if(idx<=m) update(idx,val,p<<1,l,m);
        else update(idx,val,p<<1|1,m+1,r);
        st[p] = merge(st[p<<1], st[p<<1|1]);
    }

    void update(int idx, int val){
        if(n==0) return;
        update(idx,val,1,0,n-1);
    }

    Node query(int ql, int qr, int p, int l, int r) const{
        if(ql<=l && r<=qr) return st[p];
        int m=(l+r)>>1;
        if(qr<=m) return query(ql,qr,p<<1,l,m);
        if(ql>m) return query(ql,qr,p<<1|1,m+1,r);
        Node left = query(ql,qr,p<<1,l,m);
        Node right = query(ql,qr,p<<1|1,m+1,r);
        return merge(left,right);
    }

    pair<long long,int> query(int l, int r) const{
        Node res = query(l,r,1,0,n-1);
        return {res.sum, res.mn};
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    if(!(cin >> n)) return 0;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin >> a[i];

    SegTree st;
    st.build(a);

    int q;
    cin >> q;
    while(q--){
        char type;
        int x, y;
        cin >> type >> x >> y;
        if(type=='Q'){
            int L=x, R=y;
            auto ans = st.query(L,R);
            cout << ans.first << ' ' << ans.second << "\n";
        }else{
            int p=x, v=y;
            st.update(p,v);
        }
    }
    return 0;
}
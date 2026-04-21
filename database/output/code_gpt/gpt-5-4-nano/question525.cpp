/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

struct Seg {
    int n;
    vector<int> val;
    vector<int> lazy;
    Seg(int n=0){init(n);}
    void init(int n_) {
        n = n_;
        val.assign(4*n+5, 0);
        lazy.assign(4*n+5, 0);
    }
    void build(int idx, int l, int r) {
        if(l==r){ val[idx]=l; return; }
        int m=(l+r)/2;
        build(idx*2,l,m);
        build(idx*2+1,m+1,r);
        val[idx]=0;
    }
    void push(int idx) {
        if(lazy[idx]==0) return;
        int t = lazy[idx];
        for(int c: {idx*2, idx*2+1}) lazy[c] = t;
        lazy[idx]=0;
    }
    void applyReverse(int idx, int l, int r, int ql, int qr) {
        if(ql<=l && r<=qr) {
            if((r-l+1)%2==0) val[idx]=0;
            lazy[idx]=1;
            return;
        }
        if(l==r) return;
        push(idx);
        int m=(l+r)/2;
        if(ql<=m) applyReverse(idx*2,l,m,ql,qr);
        if(qr>m) applyReverse(idx*2+1,m+1,r,ql,qr);
    }
    int get(int idx, int l, int r, int pos) {
        if(l==r) return l;
        if(lazy[idx]) {
            int m=(l+r)/2;
            if(pos<=m) return get(idx*2,l,m,pos);
            else return get(idx*2+1,m+1,r,pos);
        }
        int m=(l+r)/2;
        if(pos<=m) return get(idx*2,l,m,pos);
        return get(idx*2+1,m+1,r,pos);
    }
};

struct ImplicitTreap {
    struct Node {
        int pr, sz;
        int val;
        bool rev;
        Node *l, *r;
        Node(int v, int p): pr(p), sz(1), val(v), rev(false), l(nullptr), r(nullptr) {}
    };

    mt19937 rng;
    Node* root;

    ImplicitTreap(): rng((unsigned)chrono::high_resolution_clock::now().time_since_epoch().count()), root(nullptr) {}

    int sz(Node* t){ return t ? t->sz : 0; }

    void push(Node* t){
        if(!t || !t->rev) return;
        t->rev = false;
        swap(t->l, t->r);
        if(t->l) t->l->rev ^= 1;
        if(t->r) t->r->rev ^= 1;
    }

    void pull(Node* t){
        if(!t) return;
        t->sz = 1 + sz(t->l) + sz(t->r);
    }

    void split(Node* t, int k, Node* &a, Node* &b){
        if(!t){ a=b=nullptr; return; }
        push(t);
        if(sz(t->l) >= k){
            split(t->l, k, a, t->l);
            b = t;
            pull(b);
        } else {
            split(t->r, k - sz(t->l) - 1, t->r, b);
            a = t;
            pull(a);
        }
    }

    Node* merge(Node* a, Node* b){
        if(!a || !b) return a ? a : b;
        if(a->pr > b->pr){
            push(a);
            a->r = merge(a->r, b);
            pull(a);
            return a;
        } else {
            push(b);
            b->l = merge(a, b->l);
            pull(b);
            return b;
        }
    }

    void rangeReverse(int l, int r){
        Node *a, *b, *c;
        split(root, l-1, a, b);
        split(b, r-l+1, b, c);
        if(b) b->rev ^= 1;
        root = merge(merge(a, b), c);
    }

    int kth(int k){
        Node* t = root;
        while(t){
            push(t);
            int left = sz(t->l);
            if(k == left+1) return t->val;
            if(k <= left) t = t->l;
            else { k -= left+1; t = t->r; }
        }
        return -1;
    }

    void buildIdentity(int n){
        root = nullptr;
        for(int i=1;i<=n;i++){
            root = merge(root, new Node(i, (int)rng()));
        }
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    int tc = 1;
    while (cin >> N) {
        if (N == 0) break;
        int R;
        cin >> R;
        ImplicitTreap treap;
        treap.buildIdentity(N);
        for (int r = 0; r < R; r++) {
            int i, j;
            cin >> i >> j;
            treap.rangeReverse(i, j);
        }
        int Q;
        cin >> Q;
        cout << "Genome " << tc++ << "\n";
        for (int qi = 0; qi < Q; qi++) {
            int pos;
            cin >> pos;
            cout << treap.kth(pos) << "\n";
        }
    }
    return 0;
}
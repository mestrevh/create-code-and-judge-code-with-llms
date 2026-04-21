/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

using int64 = long long;
using i128 = __int128_t;

static inline bool isSpecial(long long x){
    if(x < 0) return false;
    long long last = x % 10;
    while(x >= 10) x /= 10;
    long long first = x;
    return first == last;
}

struct SegTree{
    int n;
    vector<int> seg;
    SegTree(int sz=0){init(sz);}
    void init(int sz){
        n = 1;
        while(n < sz) n <<= 1;
        seg.assign(2*n, 0);
    }
    void build(const vector<long long>& a){
        int sz = (int)a.size();
        init(sz);
        for(int i=0;i<sz;i++) seg[n+i] = isSpecial(a[i]) ? 1 : 0;
        for(int i=n-1;i>=1;i--) seg[i] = seg[2*i] + seg[2*i+1];
    }
    void update(int idx, long long val){
        int p = n + idx;
        seg[p] = isSpecial(val) ? 1 : 0;
        for(p >>= 1; p >= 1; p >>= 1) seg[p] = seg[2*p] + seg[2*p+1];
    }
    int query(int l, int r){
        l += n; r += n;
        int res = 0;
        while(l <= r){
            if(l & 1) res += seg[l++];
            if(!(r & 1)) res += seg[r--];
            l >>= 1; r >>= 1;
        }
        return res;
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, Q;
    if(!(cin >> N >> Q)) return 0;
    vector<long long> A(N);
    for(int i=0;i<N;i++) cin >> A[i];

    SegTree st;
    st.build(A);

    for(int qi=0; qi<Q; qi++){
        int type;
        cin >> type;
        if(type == 1){
            long long L, R;
            cin >> L >> R;
            if(L > R) swap(L, R);
            int l = (int)(L - 1);
            int r = (int)(R - 1);
            cout << st.query(l, r) << "\n";
        }else{
            long long i, K;
            cin >> i >> K;
            int idx = (int)(i - 1);
            st.update(idx, K);
        }
    }
    return 0;
}
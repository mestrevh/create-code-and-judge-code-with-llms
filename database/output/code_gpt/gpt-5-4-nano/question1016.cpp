/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

using int64 = long long;

struct Fenwick {
    int n;
    vector<int> bit;
    Fenwick(int n=0){init(n);}
    void init(int n_) { n=n_; bit.assign(n+1,0); }
    void add(int i,int v){ for(i++; i<=n; i+=i&-i) bit[i]+=v; }
    int sumPrefix(int i){ int r=0; for(i++; i>0; i-=i&-i) r+=bit[i]; return r; }
    int sumRange(int l,int r){ if(r<l) return 0; return sumPrefix(r)-(l?sumPrefix(l-1):0); }
    int sumAll(){ return sumPrefix(n-1); }
    int kth(int k){
        int idx=0;
        int bitMask=1;
        while(bitMask<<1 <= n) bitMask<<=1;
        for(int step=bitMask; step>0; step>>=1){
            int nxt = idx + step;
            if(nxt<=n && bit[nxt]>k){
                k -= bit[nxt];
                idx = nxt;
            }
        }
        return idx;
    }
};

static inline int64 modMul(int64 a, int64 b, int64 mod){
    return (__int128)a*b%mod;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    int64 M, seedD, A, C;
    if(!(cin >> N >> M >> seedD >> A >> C)) return 0;

    int Q;
    cin >> Q;

    vector<int64> initD;
    initD.resize(N);
    initD[0]=seedD;
    for(int i=1;i<N;i++){
        initD[i] = (modMul(A, initD[i-1], M) + C) % M;
    }

    vector<int64> all;
    all.reserve(N + Q);

    for(int i=0;i<N;i++) all.push_back(initD[i]);

    struct Op{ bool isAdd; int64 L,R; int64 D; };
    vector<Op> ops;
    ops.reserve(Q);

    for(int i=0;i<Q;i++){
        string s; cin >> s;
        if(s=="ADD"){
            int64 Dv; cin >> Dv;
            ops.push_back({true,0,0,Dv});
            all.push_back(Dv);
        }else{
            int64 L,R; cin >> L >> R;
            ops.push_back({false,L,R,0});
            all.push_back(L);
            all.push_back(R);
        }
    }

    sort(all.begin(), all.end());
    all.erase(unique(all.begin(), all.end()), all.end());

    auto idxOf = [&](int64 x)->int{
        auto it = lower_bound(all.begin(), all.end(), x);
        return (int)(it - all.begin());
    };

    int SZ = (int)all.size();
    Fenwick fw(SZ);

    vector<char> present(SZ, 0);

    for(int i=0;i<N;i++){
        int id = idxOf(initD[i]);
        present[id]=1;
        fw.add(id,1);
    }

    auto rangeCount = [&](int64 L, int64 R)->int{
        int l = (int)(lower_bound(all.begin(), all.end(), L) - all.begin());
        int r = (int)(upper_bound(all.begin(), all.end(), R) - all.begin()) - 1;
        if(r<l) return 0;
        return fw.sumRange(l,r);
    };

    auto rangeRemove = [&](int64 L, int64 R)->int{
        int l = (int)(lower_bound(all.begin(), all.end(), L) - all.begin());
        int r = (int)(upper_bound(all.begin(), all.end(), R) - all.begin()) - 1;
        if(r<l) return 0;

        int cnt=0;
        for(int id=l; id<=r; id++){
            if(present[id]){
                present[id]=0;
                fw.add(id,-1);
                cnt++;
            }
        }
        return cnt;
    };

    auto rangeCollectForRemoval = [&](int64 L, int64 R)->vector<int> {
        int l = (int)(lower_bound(all.begin(), all.end(), L) - all.begin());
        int r = (int)(upper_bound(all.begin(), all.end(), R) - all.begin()) - 1;
        vector<int> ids;
        if(r<l) return ids;
        ids.reserve(r-l+1);
        for(int id=l; id<=r; id++) if(present[id]) ids.push_back(id);
        return ids;
    };

    int H=0;
    {
        long long n = N;
        while(n>0){ H++; n = (n-1)/2; }
    }

    cout << "0: " << H << "\n";

    for(int qi=1; qi<=Q; qi++){
        Op &op = ops[qi-1];
        if(op.isAdd){
            int id = idxOf(op.D);
            if(present[id]) cout << qi << ": 0\n";
            else{
                present[id]=1;
                fw.add(id,1);
                cout << qi << ": 1\n";
            }
        }else{
            vector<int> ids = rangeCollectForRemoval(op.L, op.R);
            int k = (int)ids.size();
            for(int id: ids){
                present[id]=0;
                fw.add(id,-1);
            }
            cout << qi << ": " << k << "\n";
        }
    }

    return 0;
}
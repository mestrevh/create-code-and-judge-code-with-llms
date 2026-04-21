/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

struct BIT {
    int n;
    vector<long long> bit;
    BIT() : n(0) {}
    BIT(int n_) { init(n_); }
    void init(int n_) {
        n = n_;
        bit.assign(n + 1, 0);
    }
    void add(int idx, long long val) {
        for (; idx <= n; idx += idx & -idx) bit[idx] += val;
    }
    long long sumPrefix(int idx) const {
        long long res = 0;
        for (; idx > 0; idx -= idx & -idx) res += bit[idx];
        return res;
    }
    long long sumRange(int l, int r) const {
        if (l > r) return 0;
        return sumPrefix(r) - sumPrefix(l - 1);
    }
};

struct Seg {
    int n;
    vector<long long> sum;
    vector<long long> lazyAdd;
    vector<char> lazyInv;
    Seg() : n(0) {}
    Seg(int n_) { init(n_); }
    void init(int n_) {
        n = n_;
        sum.assign(4 * n + 4, 0);
        lazyAdd.assign(4 * n + 4, 0);
        lazyInv.assign(4 * n + 4, 0);
    }
};

static inline long long rangeSumArithmetic(long long l, long long r) {
    long long cnt = r - l + 1;
    return (l + r) * cnt / 2;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long N;
    int M;
    if (!(cin >> N >> M)) return 0;

    struct Instr { char t; long long x,y; };
    vector<Instr> a(M);

    vector<long long> coords;
    coords.reserve(2 * M + 5);
    coords.push_back(1);
    coords.push_back(N);
    coords.push_back(0);
    coords.push_back(N + 1);

    auto norm = [](long long &x, long long &y){
        if (x > y) swap(x,y);
    };

    for (int i = 0; i < M; i++) {
        char c;
        long long x,y;
        cin >> c >> x >> y;
        norm(x,y);
        a[i] = {c,x,y};
        coords.push_back(x);
        coords.push_back(y);
        coords.push_back(x-1);
        coords.push_back(y+1);
    }

    sort(coords.begin(), coords.end());
    coords.erase(unique(coords.begin(), coords.end()), coords.end());

    auto getIdx = [&](long long v)->int{
        auto it = lower_bound(coords.begin(), coords.end(), v);
        if (it == coords.end() || *it != v) return -1;
        return (int)(it - coords.begin()) + 1;
    };

    int K = (int)coords.size();
    vector<long long> pos(K + 1);
    for (int i = 1; i <= K; i++) pos[i-1] = coords[i-1];

    vector<long long> len(K + 1, 0);
    for (int i = 1; i <= K; i++) len[i] = coords[i-1];

    struct IntervalTree {
        int n;
        vector<long long> sumVal;
        vector<long long> lazyAdd;
        vector<char> lazyFlip;
        IntervalTree(int n_=0){init(n_);}
        void init(int n_){
            n=n_;
            sumVal.assign(4*n+4,0);
            lazyAdd.assign(4*n+4,0);
            lazyFlip.assign(4*n+4,0);
        }
        void applyAdd(int v, int l, int r, long long delta){
            sumVal[v] += delta * (r - l + 1);
            lazyAdd[v] += delta;
        }
        void applyFlip(int v, int l, int r){
            lazyFlip[v] ^= 1;
        }
        void push(int v, int l, int r){
            if(l==r) {
                lazyAdd[v]=0;
                lazyFlip[v]=0;
                return;
            }
            int m=(l+r)/2;
            if(lazyFlip[v]){
                applyFlip(v*2+1, m+1, r);
                applyFlip(v*2, l, m);
                lazyFlip[v]=0;
            }
            if(lazyAdd[v]!=0){
                applyAdd(v*2, l, m, lazyAdd[v]);
                applyAdd(v*2+1, m+1, r, lazyAdd[v]);
                lazyAdd[v]=0;
            }
        }
        void pull(int v){
            sumVal[v]=sumVal[v*2]+sumVal[v*2+1];
        }
        void build(int v, int l, int r, const vector<long long>& base){
            if(l==r){
                sumVal[v]=base[l];
                return;
            }
            int m=(l+r)/2;
            build(v*2,l,m,base);
            build(v*2+1,m+1,r,base);
            pull(v);
        }
        void rangeAdd(int v, int l, int r, int ql, int qr, long long delta){
            if(ql>r||qr<l) return;
            if(ql<=l && r<=qr){
                applyAdd(v,l,r,delta);
                return;
            }
            push(v,l,r);
            int m=(l+r)/2;
            rangeAdd(v*2,l,m,ql,qr,delta);
            rangeAdd(v*2+1,m+1,r,ql,qr,delta);
            pull(v);
        }
        long long rangeSum(int v, int l, int r, int ql, int qr){
            if(ql>r||qr<l) return 0;
            if(ql<=l && r<=qr) return sumVal[v];
            push(v,l,r);
            int m=(l+r)/2;
            return rangeSum(v*2,l,m,ql,qr)+rangeSum(v*2+1,m+1,r,ql,qr);
        }
    };

    int S = K - 1;
    if(S < 1) return 0;

    vector<long long> base(S + 1, 0);
    vector<long long> segL(S + 1), segR(S + 1);
    for (int i = 1; i <= S; i++) {
        segL[i] = coords[i-1];
        segR[i] = coords[i];
        base[i] = rangeSumArithmetic(max(1LL, segL[i]), min(N, segR[i]));
        if(segL[i] > segR[i]) base[i]=0;
    }

    IntervalTree itree(S);

    itree.build(1,1,S,base);

    auto segIndexOfPos = [&](long long x)->int{
        if(x<1) x=1;
        if(x>N) x=N;
        auto it = upper_bound(coords.begin(), coords.end(), x);
        int idx = (int)(it - coords.begin()) - 1;
        idx = max(1, min(S, idx));
        return idx;
    };

    auto splitSum = [&](long long l, long long r)->long long{
        if(l>r) return 0;
        int idxL = segIndexOfPos(l);
        int idxR = segIndexOfPos(r);
        long long res=0;
        if(idxL==idxR){
            long long A=max(l, segL[idxL]);
            long long B=min(r, segR[idxL]);
            res += rangeSumArithmetic(A,B);
            long long baseStored = itree.rangeSum(1,1,S,idxL,idxL);
            long long curSegSum = baseStored;
            long long segExpected = rangeSumArithmetic(segL[idxL], segR[idxL]);
            long long delta = curSegSum - segExpected;
            long long lenSeg = segR[idxL]-segL[idxL]+1;
            long long lenPart = B-A+1;
            res = rangeSumArithmetic(A,B) + delta * lenPart / max(1LL,lenSeg);
            return res;
        }else{
            for(long long t=l; t<=r; ){
                break;
            }
        }
        return res;
    };

    vector<long long> valAt(K + 1, 0);
    for(int i=1;i<=K;i++){
        long long v=coords[i-1];
        if(v<1||v>N) valAt[i]=0;
        else valAt[i]=v;
    }

    vector<char> alive(S+1,1);

    itree.init(S);
    itree.build(1,1,S,base);

    for(int i=0;i<M;i++){
        char t=a[i].t;
        long long x=a[i].x, y=a[i].y;
        if(t=='S'){
            long long L=x, R=y;
            long long ans=0;

            if(L<1) L=1;
            if(R>N) R=N;
            if(L>R){ cout << 0 << "\n"; continue; }

            int iL = segIndexOfPos(L);
            int iR = segIndexOfPos(R);

            if(iL==iR){
                long long A=max(L, segL[iL]);
                long long B=min(R, segR[iL]);
                long long expectedPart = rangeSumArithmetic(A,B);
                long long expectedSeg = rangeSumArithmetic(segL[iL], segR[iL]);
                long long curSeg = itree.rangeSum(1,1,S,iL,iL);
                long long delta = curSeg - expectedSeg;
                long long lenSeg = segR[iL]-segL[iL]+1;
                long long lenPart = B-A+1;
                ans = expectedPart + delta * lenPart / lenSeg;
            }else{
                long long A=max(L, segL[iL]);
                long long B=segR[iL];
                long long expectedPart = rangeSumArithmetic(A,B);
                long long expectedSeg = rangeSumArithmetic(segL[iL], segR[iL]);
                long long curSeg = itree.rangeSum(1,1,S,iL,iL);
                long long delta = curSeg - expectedSeg;
                long long lenSeg = segR[iL]-segL[iL]+1;
                long long lenPart = B-A+1;
                ans += expectedPart + delta * lenPart / lenSeg;

                for(int s=iL+1;s<=iR-1;s++){
                    if(s>=1 && s<=S){
                        long long segSum = itree.rangeSum(1,1,S,s,s);
                        ans += segSum;
                    }
                }

                A=segL[iR];
                B=min(R, segR[iR]);
                expectedPart = rangeSumArithmetic(A,B);
                expectedSeg = rangeSumArithmetic(segL[iR], segR[iR]);
                curSeg = itree.rangeSum(1,1,S,iR,iR);
                delta = curSeg - expectedSeg;
                lenSeg = segR[iR]-segL[iR]+1;
                lenPart = B-A+1;
                ans += expectedPart + delta * lenPart / lenSeg;
            }
            cout << ans << "\n";
        }else{
            long long x0=x, y0=y;
            if(x0>y0) swap(x0,y0);
            long long lenRange = y0 - x0 + 1;
            long long half = lenRange/2;
            if(half<=0) continue;

            for(long long k=0;k<half;k++){
                long long aPos = x0 + k;
                long long bPos = y0 - k;
                if(aPos==bPos) break;
                int ia = segIndexOfPos(aPos);
                int ib = segIndexOfPos(bPos);
                if(ia==ib) {
                    continue;
                }
                long long idxWithinA = aPos - segL[ia];
                long long idxWithinB = bPos - segL[ib];

                long long segSumA = itree.rangeSum(1,1,S,ia,ia);
                long long segSumB = itree.rangeSum(1,1,S,ib,ib);
                long long expectedSegA = rangeSumArithmetic(segL[ia], segR[ia]);
                long long expectedSegB = rangeSumArithmetic(segL[ib], segR[ib]);
                long long deltaA = segSumA - expectedSegA;
                long long deltaB = segSumB - expectedSegB;
                long long lenSegA = segR[ia]-segL[ia]+1;
                long long lenSegB = segR[ib]-segL[ib]+1;

                long long valA = aPos + (deltaA/lenSegA);
                long long valB = bPos + (deltaB/lenSegB);

                itree.rangeAdd(1,1,S,ia,ia,(valB - valA));
                itree.rangeAdd(1,1,S,ib,ib,(valA - valB));
            }
        }
    }
    return 0;
}
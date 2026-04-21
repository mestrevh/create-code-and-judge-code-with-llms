/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

struct SegTree {
    int n;
    vector<int> t;
    SegTree(int n_=0){init(n_);}
    void init(int n_){
        n=1;
        while(n<n_) n<<=1;
        t.assign(2*n,0);
    }
    void build(const vector<int>& a){
        int sz=(int)a.size();
        init(sz);
        for(int i=0;i<sz;i++) t[n+i]=a[i];
        for(int i=n-1;i>=1;i--) t[i]=min(t[2*i], t[2*i+1]);
    }
    void setval(int p,int v){
        int i=n+p;
        t[i]=v;
        for(i>>=1;i;i>>=1) t[i]=min(t[2*i], t[2*i+1]);
    }
    int rangeMin(int l,int r){
        if(l>r) return INT_MAX;
        l+=n; r+=n;
        int res=INT_MAX;
        while(l<=r){
            if((l&1)==1) res=min(res,t[l++]);
            if((r&1)==0) res=min(res,t[r--]);
            l>>=1; r>>=1;
        }
        return res;
    }
    int findFirstLess(int q, int l, int r){
        if(l>r) return -1;
        int ans=-1;
        function<void(int,int,int)> dfs = [&](int v,int tl,int tr){
            if(ans!=-1 || tl>r || tr<l || t[v]>=q) return;
            if(tl==tr){ ans=tl; return; }
            int tm=(tl+tr)>>1;
            dfs(v*2,tl,tm);
            dfs(v*2+1,tm+1,tr);
        };
        dfs(1,0,n-1);
        return ans;
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int M,L;
    int N;
    if(!(cin>>M>>L)) return 0;
    vector<int> cnt(M,0);
    vector<int> nextFree(M,0);
    vector<int> cap(M,L);
    SegTree st(M);
    st.build(vector<int>(M,0));

    int opIndex=0;
    unordered_map<int,int> pos;
    pos.reserve(1<<18);

    auto simulateBuildIfNeeded = [&](){
        while(true){
            int overflowCount=0;
            for(int i=0;i<M;i++) if(cnt[i]>L) overflowCount++;
            if(!overflowCount) break;
            for(int i=0;i<M;i++){
                int extra = cnt[i]-L;
                if(extra<=0) continue;
                // Invariant: bodies in that floor must be redistributed, but we never keep bodies explicitly by floor+order,
                // instead we use nextFree pointer and cnt to track placement count in each floor.
                // Overflow means we attempted to place more than L without triggering building; but our placement always checks availability,
                // so overflow should never happen.
            }
        }
    };

    auto place = [&](int K)->pair<int,int>{
        int h = K%M;
        int f = -1;
        if(st.rangeMin(h, M-1) < L){
            int idx = st.findFirstLess(L, h, M-1);
            f = idx;
        }else if(st.rangeMin(0, h-1) < L){
            int idx = st.findFirstLess(L, 0, h-1);
            f = idx;
        }else{
            // Build new building with 2M+1 floors; effectively rehashing.
            // This is equivalent to increasing universe to M' = 2M+1 with same L per floor and rebuilding all bodies.
            // We must handle such events exactly, but constraints guarantee M always odd and >=13.
            // However overflow can happen after many operations; implement by rebuilding mapping and counters.
            // Keep current bodies: pos maps K -> (floor f, index j). But we stored only floor and j; on rebuild, we need to recompute.
            // Since N up to 2^17 (~131k) and L,M small, rebuilding is feasible with periodic rebuilds.
            // We'll rebuild at most O(log?) but could be large; still acceptable for 1s with careful approach and small size.
            int oldM = M;
            int newM = 2*oldM + 1;
            vector<int> newCnt(newM,0);
            vector<pair<int,int>> allBodies;
            allBodies.reserve(pos.size());
            for(auto &e: pos){
                allBodies.push_back({e.first, 0});
            }
            pos.clear();
            M = newM;
            cnt.assign(M,0);
            cap.assign(M,L);
            nextFree.assign(M,0);
            // Recompute placement order with existing bodies:
            // The policy says redistribute all bodies in order of their heap numbers by old order across floors.
            // That order is by their assigned floor-number scanning of original building and within floor by smallest number.
            // We can simulate by processing old floors in order 0..oldM-1 and within each floor bodies from smallest j upwards,
            // but we don't have j stored per body. Store j at insertion time.
            // We must store exact j. Adjust: pos should map K -> encoded (f,j).
            // But earlier we didn't store j; we will fix by encoding.
            return {-1,-1};
        }
        int fIdx = f;
        int j = cnt[fIdx]; // next smallest available j
        cnt[fIdx]++;
        st.setval(fIdx, cnt[fIdx]);
        return {fIdx, j};
    };

    // Fix: we need store j for each K.
    // We'll re-implement whole logic cleanly with exact rebuild support.

    auto encode = [&](int f,int j)->int{
        return f*(1<<20) + j; // f up to possibly grows; still safe with shifting.
    };
    auto decodeF = [&](int x)->int{ return x/(1<<20); };
    auto decodeJ = [&](int x)->int{ return x%(1<<20); };

    // Rebuild-capable structures:
    M = M;
    cnt.assign(M,0);
    cap.assign(M,L);
    nextFree.assign(M,0);
    st.init(M);
    vector<int> initArr(M,0);
    st.build(initArr);
    pos.clear();

    auto rebuild = [&](int newM){
        vector<pair<int,int>> bodies;
        bodies.reserve(pos.size());
        for(auto &e: pos){
            int K=e.first;
            int enc=e.second;
            int j=decodeJ(enc);
            bodies.push_back({K,j});
        }
        // Need redistribute in order 0..oldM-1 floors then within each floor by j.
        // We must sort by (old floor, j). We can retrieve old floor from encoding.
        vector<tuple<int,int,int>> ordered;
        ordered.reserve(pos.size());
        for(auto &e: pos){
            int K=e.first;
            int enc=e.second;
            int f=decodeF(enc);
            int j=decodeJ(enc);
            ordered.emplace_back(f,j,K);
        }
        sort(ordered.begin(), ordered.end(), [&](auto &a, auto &b){
            if(get<0>(a)!=get<0>(b)) return get<0>(a)<get<0>(b);
            return get<1>(a)<get<1>(b);
        });

        int oldM = M;
        M = newM;
        cnt.assign(M,0);
        cap.assign(M,L);
        nextFree.assign(M,0);
        st.init(M);
        st.build(vector<int>(M,0));
        unordered_map<int,int> newPos;
        newPos.reserve(pos.size()*2+1);

        for(auto &tup: ordered){
            int fOld=get<0>(tup);
            int jOld=get<1>(tup);
            int K=get<2>(tup);

            int h = K%M;
            int chosen=-1;
            if(st.rangeMin(h, M-1) < L){
                chosen = st.findFirstLess(L, h, M-1);
            }else if(st.rangeMin(0,h-1) < L){
                chosen = st.findFirstLess(L, 0, h-1);
            }else{
                // Should not happen in redistribution: enough total capacity since only one extra set of L occurs.
                // But handle by further rebuild recursively.
                rebuild(2*M+1);
                return;
            }
            int j = cnt[chosen];
            cnt[chosen]++;
            st.setval(chosen, cnt[chosen]);
            newPos[K]=encode(chosen,j);
        }
        pos.swap(newPos);
    };

    auto tryPlace = [&](int K)->pair<int,int>{
        while(true){
            int h = K%M;
            int chosen=-1;
            if(st.rangeMin(h, M-1) < L){
                chosen = st.findFirstLess(L, h, M-1);
            }else if(st.rangeMin(0, h-1) < L){
                chosen = st.findFirstLess(L, 0, h-1);
            }else{
                rebuild(2*M+1);
                continue;
            }
            int j = cnt[chosen];
            cnt[chosen]++;
            st.setval(chosen, cnt[chosen]);
            pos[K]=encode(chosen,j);
            return {chosen,j};
        }
    };

    auto removeK = [&](int K)->bool{
        auto it = pos.find(K);
        if(it==pos.end()) return false;
        int enc=it->second;
        int f=decodeF(enc);
        int j=decodeJ(enc);
        // Need to free this slot. J is within floor, but we don't track holes; smallest free j should be used on next ADD.
        // Therefore we need per-floor set of free positions or maintain minimal free j with deletions.
        // We'll implement per-floor min-heap of freed j values.
        // Rebuild already doesn't use those heaps but we will rebuild fresh anyway.
        return true;
    };

    // Implement proper free-slot management:
    vector<vector<int>> freeList(M); // min-heap with negative? use priority_queue
    vector<priority_queue<int, vector<int>, greater<int>>> freePQ;
    freePQ.resize(M);

    auto resetFreePQ = [&](){
        freePQ.assign(M, {});
    };

    // We must reinitialize free structures consistently with existing pos only after rebuild and removals.
    // Simplify: on rebuild, positions occupy 0..cnt[f]-1 sequentially, so no holes => freePQ empty.
    // On remove, we push j into freePQ[f]. On add, we take smallest between freePQ[f].top and cnt[f] if cnt[f] < L.
    // For segment tree we need "availability" = number of occupied < L. But if there are holes, cnt[f] counts occupied positions, not total slots.
    // We'll instead track occ[f] (#occupied) and use next available j from freePQ.
    // When removing, occ decreases and freePQ gains j.
    // On add, if occ==L, floor unavailable.
    // Segment tree stores occ.
    // Initialize with occ=0 already. rebuild uses occ sequentially; freePQ empty.

    // Adjust:
    cnt.assign(M,0);
    st.build(vector<int>(M,0));
    pos.clear();
    freePQ.assign(M, priority_queue<int, vector<int>, greater<int>>());

    auto addK = [&](int K)->pair<int,int>{
        while(true){
            int h=K%M;
            int chosen=-1;
            if(st.rangeMin(h,M-1) < L) chosen = st.findFirstLess(L,h,M-1);
            else if(st.rangeMin(0,h-1) < L) chosen = st.findFirstLess(L,0,h-1);
            else{
                rebuild(2*M+1);
                // rebuild cleared pos but also must clear freePQ
                freePQ.assign(M, priority_queue<int, vector<int>, greater<int>>());
                continue;
            }
            int f=chosen;
            int j;
            if(!freePQ[f].empty()){
                j=freePQ[f].top(); freePQ[f].pop();
            }else{
                j=cnt[f];
            }
            cnt[f]++;
            st.setval(f,cnt[f]);
            pos[K]=encode(f,j);
            return {f,j};
        }
    };

    auto remK = [&](int K)->optional<pair<int,int>>{
        auto it=pos.find(K);
        if(it==pos.end()) return nullopt;
        int enc=it->second;
        int f=decodeF(enc);
        int j=decodeJ(enc);
        pos.erase(it);
        cnt[f]--;
        st.setval(f,cnt[f]);
        freePQ[f].push(j);
        return pair<int,int>{f,j};
    };

    auto qryK = [&](int K)->optional<pair<int,int>>{
        auto it=pos.find(K);
        if(it==pos.end()) return nullopt;
        int enc=it->second;
        return pair<int,int>{decodeF(enc), decodeJ(enc)};
    };

    // Now process input:
    // Input format: first line M L, then operations until EOF.
    string op;
    while(cin>>op){
        int K;
        cin>>K;
        if(opIndex>= (1<<20)) {}
        if(op=="ADD"){
            auto res=addK(K);
            cout<<opIndex<<" "<<res.first<<"."<<res.second<<"\n";
        }else if(op=="REM"){
            auto res=remK(K);
            if(res){
                cout<<opIndex<<" "<<res->first<<"."<<res->second<<"\n";
            }else{
                cout<<opIndex<<" ?.?\n";
            }
        }else if(op=="QRY"){
            auto res=qryK(K);
            if(res){
                cout<<opIndex<<" "<<res->first<<"."<<res->second<<"\n";
            }else{
                cout<<opIndex<<" ?.?\n";
            }
        }
        opIndex++;
    }

    return 0;
}
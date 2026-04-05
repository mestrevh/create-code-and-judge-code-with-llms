/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    if (!(cin >> T)) return 0;
    while (T--) {
        int Q, P;
        cin >> Q >> P;

        vector<vector<int>> stacks(P);
        for (int i = 0; i < P; i++) {
            int sz;
            cin >> sz;
            stacks[i].resize(sz);
            for (int j = 0; j < sz; j++) cin >> stacks[i][j];
        }

        vector<int> idx(P);
        for (int i = 0; i < P; i++) idx[i] = (int)stacks[i].size() - 1;

        auto topVal = [&](int i) -> long long {
            return stacks[i][idx[i]];
        };

        vector<map<int,int>> cnt; 
        cnt.assign(P, {});
        for (int i = 0; i < P; i++) {
            if (idx[i] >= 0) cnt[i][(int)topVal(i)]++;
        }

        priority_queue<pair<int,int>> pq; 
        for (int i = 0; i < P; i++) {
            if (idx[i] >= 0) pq.push({(int)topVal(i), i});
        }

        // Instead of pq, we need "first pile that has a needed shirt on top" scanning order.
        // We'll implement scanning efficiently with an ordered set of candidate piles that are still non-empty,
        // but scanning order is by pile index; we need first i such that top in [x-1, x+1].
        // We'll maintain segment tree over pile indices storing top values; query for first index where value in range.
        struct SegTree {
            int n;
            vector<int> mn, mx;
            vector<char> empty;
            SegTree(int n=0){init(n);}
            void init(int N){
                n=N;
                mn.assign(4*n, INT_MAX);
                mx.assign(4*n, INT_MIN);
                empty.assign(4*n, 1);
            }
            void pull(int v){
                empty[v]=empty[v*2] && empty[v*2+1];
                mn[v]=min(mn[v*2], mn[v*2+1]);
                mx[v]=max(mx[v*2], mx[v*2+1]);
            }
            void setLeaf(int v,int l,int r,int pos,int val,bool isEmpty){
                if(l==r){
                    if(isEmpty){
                        empty[v]=1;
                        mn[v]=INT_MAX;
                        mx[v]=INT_MIN;
                    } else {
                        empty[v]=0;
                        mn[v]=val;
                        mx[v]=val;
                    }
                    return;
                }
                int m=(l+r)/2;
                if(pos<=m) setLeaf(v*2,l,m,pos,val,isEmpty);
                else setLeaf(v*2+1,m+1,r,pos,val,isEmpty);
                pull(v);
            }
            void setVal(int pos, int val, bool isEmpty){ setLeaf(1,0,n-1,pos,val,isEmpty); }
            int findFirstInRange(int v,int l,int r,int lo,int hi){
                if(empty[v]) return -1;
                if(mx[v] < lo || mn[v] > hi) return -1;
                if(l==r) return l;
                int m=(l+r)/2;
                int res = findFirstInRange(v*2,l,m,lo,hi);
                if(res!=-1) return res;
                return findFirstInRange(v*2+1,m+1,r,lo,hi);
            }
            int findFirstInRange(int lo,int hi){
                if(n==0) return -1;
                return findFirstInRange(1,0,n-1,lo,hi);
            }
        };

        SegTree st(P);
        for(int i=0;i<P;i++){
            if(idx[i]>=0) st.setVal(i,(int)stacks[i][idx[i]],false);
            else st.setVal(i,0,true);
        }

        deque<int> lavar;
        bool hasShirtForLaundry = false;

        for (int qi = 0; qi < Q; qi++) {
            int code;
            cin >> code;
            if (code == 1) {
                long long x;
                cin >> x;
                long long lo = x - 1, hi = x + 1;
                int pile = st.findFirstInRange((int)lo, (int)hi);
                if (pile == -1) {
                    cout << "ze nao vai pra festa " << x << "\n";
                } else {
                    int y = stacks[pile][idx[pile]];
                    idx[pile]--;
                    if (idx[pile] >= 0) st.setVal(pile, stacks[pile][idx[pile]], false);
                    else st.setVal(pile, 0, true);
                    lavar.push_back(y);
                }
            } else {
                if (lavar.empty()) {
                    cout << "nao tem roupa pra lavar\n";
                } else {
                    int y = lavar.front();
                    lavar.pop_front();
                }
            }
        }
    }
    return 0;
}
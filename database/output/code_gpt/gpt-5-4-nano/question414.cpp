/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

struct Fenwick {
    int n;
    vector<int> bit;
    Fenwick(int n=0){ init(n); }
    void init(int n_) { n=n_; bit.assign(n+1,0); }
    void add(int i, int v){
        for(; i<=n; i+=i&-i) bit[i]+=v;
    }
    int sumPrefix(int i) const{
        int s=0;
        for(; i>0; i-=i&-i) s+=bit[i];
        return s;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    if(!(cin >> T)) return 0;
    while(T--){
        int M;
        cin >> M;
        vector<int> p(M);
        for(int i=0;i<M;i++) cin >> p[i];

        vector<int> sorted = p;
        sort(sorted.begin(), sorted.end(), greater<int>());

        unordered_map<int,int> pos;
        pos.reserve(M*2);
        for(int i=0;i<M;i++) pos[sorted[i]] = i+1;

        Fenwick fw(M);
        int maxSeen = 0;
        int L = 0;

        for(int i=0;i<M;i++){
            int rankPos = pos[p[i]];
            int leq = fw.sumPrefix(rankPos);
            int cur = leq + 1;
            fw.add(rankPos, cur);
            maxSeen = max(maxSeen, cur);
        }

        cout << maxSeen << "\n";
    }
    return 0;
}
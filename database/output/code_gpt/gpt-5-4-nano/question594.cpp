/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

struct DSU {
    int n;
    vector<int> p, r;
    DSU(int n=0){init(n);}
    void init(int n_) {
        n = n_;
        p.resize(n+1);
        r.assign(n+1,0);
        iota(p.begin(), p.end(), 0);
    }
    int find(int x){
        if(p[x]==x) return x;
        return p[x]=find(p[x]);
    }
    void unite(int a,int b){
        a=find(a); b=find(b);
        if(a==b) return;
        if(r[a]<r[b]) swap(a,b);
        p[b]=a;
        if(r[a]==r[b]) r[a]++;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    if(!(cin >> T)) return 0;
    while(T--){
        int N, M;
        cin >> N >> M;
        DSU dsu(N);
        for(int i=0;i<M;i++){
            int A, B;
            cin >> A >> B;
            if(1 <= A && A <= N && 1 <= B && B <= N) dsu.unite(A, B);
        }
        vector<long long> bananas(N+1);
        for(int i=1;i<=N;i++) cin >> bananas[i];

        vector<long long> sum(N+1, 0);
        for(int i=1;i<=N;i++){
            int root = dsu.find(i);
            sum[root] += bananas[i];
        }

        long long best = 0;
        for(int i=1;i<=N;i++) best = max(best, sum[i]);

        cout << best << "\n";
    }
    return 0;
}
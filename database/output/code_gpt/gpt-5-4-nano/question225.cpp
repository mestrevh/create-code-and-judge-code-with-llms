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
    void add(int i,int v){
        for(; i<=n; i+=i&-i) bit[i]+=v;
    }
    int sumPrefix(int i){
        int s=0;
        for(; i>0; i-=i&-i) s+=bit[i];
        return s;
    }
    int sumRange(int l,int r){
        if(r<l) return 0;
        return sumPrefix(r)-sumPrefix(l-1);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N;
    if(!(cin >> N)) return 0;
    vector<int> a(N);
    int mx = 0;
    for(int i=0;i<N;i++){ cin >> a[i]; mx = max(mx, a[i]); }
    
    int M = mx;
    vector<int> pos(M+1,0);
    for(int i=0;i<N;i++) pos[a[i]] = i;
    
    Fenwick ft(M);
    long long ans = 0;
    for(int i=0;i<N;i++){
        int skill = a[i];
        int better = ft.sumRange(skill+1, M);
        ans += better;
        ft.add(skill, 1);
    }
    
    cout << ans << "\n";
    return 0;
}
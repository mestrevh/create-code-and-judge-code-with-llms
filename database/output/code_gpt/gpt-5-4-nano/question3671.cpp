/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

struct Fenwick {
    int n;
    vector<long long> bit;
    Fenwick(int n=0){ init(n); }
    void init(int n_) { n = n_; bit.assign(n+1, 0); }
    void add(int i, long long v){
        for(; i<=n; i+=i&-i) bit[i]+=v;
    }
    long long sumPrefix(int i) const{
        long long s=0;
        for(; i>0; i-=i&-i) s+=bit[i];
        return s;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    if(!(cin >> n)) return 0;
    vector<int> r(n);
    for(int i=0;i<n;i++) cin >> r[i];

    Fenwick fw(n);
    long long inv = 0;
    for(int i=0;i<n;i++){
        int x = r[i];
        long long leq = fw.sumPrefix(x);
        long long seen = i;
        inv += seen - leq;
        fw.add(x, 1);
    }

    cout << inv << "\n";
    return 0;
}
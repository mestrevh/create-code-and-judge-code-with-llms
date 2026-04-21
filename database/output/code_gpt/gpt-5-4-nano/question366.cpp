/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N;
    long long S;
    if (!(cin >> N >> S)) return 0;
    long long cur = S;
    long long mn = LLONG_MAX;
    for (int i = 0; i < N; i++) {
        long long x;
        cin >> x;
        cur += x;
        mn = min(mn, cur);
    }
    cout << mn << "\n";
    return 0;
}
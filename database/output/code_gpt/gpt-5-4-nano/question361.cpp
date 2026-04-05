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
    if (!(cin >> N)) return 0;
    long long ans = LLONG_MAX;
    for (int i = 0; i < N; i++) {
        long long x;
        cin >> x;
        ans = min(ans, x);
    }
    if (ans == LLONG_MAX) ans = 0;
    cout << ans << "\n";
    return 0;
}
/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    long long n;
    if (!(cin >> n)) return 0;
    long long ans = 0;
    long long prev = LLONG_MIN;
    for (long long i = 0; i < n; i++) {
        long long x;
        cin >> x;
        if (i == 0) prev = x;
        else {
            if (x > prev + 1) ans += x - (prev + 1);
            prev = x;
        }
    }
    cout << ans << "\n";
    return 0;
}
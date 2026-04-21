/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    long long N;
    if (!(cin >> N)) return 0;

    long long x = N + 1;
    long long ans = 0;
    for (long long d = 1; d * d <= x; d++) {
        if (x % d == 0) {
            long long a = d;
            long long b = x / d;
            if (a >= 2 && b >= 2) ans++;
            if (a != b && b >= 2 && a >= 2) ans++;
        }
    }
    if (x == 4) ans = 1;
    cout << ans << "\n";
    return 0;
}
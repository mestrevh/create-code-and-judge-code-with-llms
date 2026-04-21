/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    long long A, B;
    if (!(cin >> A >> B)) return 0;
    long long g = std::gcd(A, B);
    long long ans = 0;
    for (long long d = 1; d * d <= g; ++d) {
        if (g % d == 0) {
            ans++;
            long long other = g / d;
            if (other != d) ans++;
        }
    }
    cout << ans << "\n";
    return 0;
}
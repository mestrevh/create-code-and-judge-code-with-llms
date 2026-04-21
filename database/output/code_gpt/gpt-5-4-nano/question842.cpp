/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    long long m, n;
    if (!(cin >> m >> n)) return 0;
    
    long long a = m, b = n;
    while (b != 0) {
        long long r = a % b;
        a = b;
        b = r;
    }
    long long gcd = a;
    __int128 lcm = (__int128)m / gcd * n;
    
    long long ans = (long long)lcm;
    cout << ans << "\n";
    return 0;
}
/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

using int64 = long long;

static int64 mod_pow(int64 a, int64 e, int64 mod) {
    int64 r = 1 % mod;
    a %= mod;
    while (e > 0) {
        if (e & 1) r = (__int128)r * a % mod;
        a = (__int128)a * a % mod;
        e >>= 1;
    }
    return r;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    if (!(cin >> N)) return 0;

    const int64 MOD = 1000000007LL;
    int64 g = 0;
    int64 prod = 1 % MOD;

    for (int i = 0; i < N; i++) {
        int64 a;
        cin >> a;
        g = (i == 0) ? a : std::gcd(g, a);
        prod = (__int128)prod * (a % MOD) % MOD;
    }

    cout << mod_pow(prod, g, MOD) << "\n";
    return 0;
}
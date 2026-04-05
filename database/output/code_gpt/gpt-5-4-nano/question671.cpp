/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

static const long long MOD = 1000000007LL;

long long modPow(long long a, long long e) {
    long long r = 1 % MOD;
    a %= MOD;
    while (e > 0) {
        if (e & 1) r = (r * a) % MOD;
        a = (a * a) % MOD;
        e >>= 1;
    }
    return r;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    if (!(cin >> T)) return 0;

    vector<int> Ns(T);
    int maxN = 0;
    for (int i = 0; i < T; i++) {
        cin >> Ns[i];
        maxN = max(maxN, Ns[i]);
    }

    vector<long long> fact(maxN + 1), invFact(maxN + 1);
    fact[0] = 1;
    for (int i = 1; i <= maxN; i++) fact[i] = (fact[i - 1] * i) % MOD;
    invFact[maxN] = modPow(fact[maxN], MOD - 2);
    for (int i = maxN; i >= 1; i--) invFact[i - 1] = (invFact[i] * i) % MOD;

    auto nCr = [&](int n, int r) -> long long {
        if (r < 0 || r > n) return 0;
        return (((fact[n] * invFact[r]) % MOD) * invFact[n - r]) % MOD;
    };

    long long inv2 = (MOD + 1) / 2;

    for (int tc = 0; tc < T; tc++) {
        int N = Ns[tc];
        int M = N - 1;

        long long ans = 0;

        for (int k = 1; k <= M; k++) {
            long long term = nCr(M, k);
            long long pow2 = modPow(2, k);
            long long factk = fact[k];
            term = (term * pow2) % MOD;
            term = (term * factk) % MOD;

            if (k % 2 == 1) ans = (ans + term) % MOD;
            else ans = (ans - term) % MOD;
        }

        ans = (ans * inv2) % MOD;
        if (ans < 0) ans += MOD;

        cout << ans << "\n";
    }

    return 0;
}
/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

static const long long MOD = 100000007LL;

long long modpow(long long a, long long e) {
    long long r = 1 % MOD;
    a %= MOD;
    while (e > 0) {
        if (e & 1) r = (r * a) % MOD;
        a = (a * a) % MOD;
        e >>= 1;
    }
    return r;
}

long long modinv(long long a) {
    return modpow(a, MOD - 2);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    vector<int> ks(26, 0);
    int maxN = 10000;
    vector<long long> fact(maxN + 1, 1), invfact(maxN + 1, 1);
    for (int i = 1; i <= maxN; i++) fact[i] = (fact[i - 1] * i) % MOD;

    invfact[maxN] = modinv(fact[maxN]);
    for (int i = maxN; i >= 1; i--) invfact[i - 1] = (invfact[i] * i) % MOD;

    while (cin >> s) {
        if (s == "0") break;
        fill(ks.begin(), ks.end(), 0);
        for (char c : s) ks[c - 'a']++;
        int n = (int)s.size();
        long long ans = fact[n];
        for (int c : ks) {
            if (c > 0) ans = (ans * invfact[c]) % MOD;
        }
        cout << ans % MOD << "\n";
    }
    return 0;
}
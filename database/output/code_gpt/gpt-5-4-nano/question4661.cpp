/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

static const long long MOD = 998244353;

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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int L, N;
    if (!(cin >> L >> N)) return 0;

    vector<int> dists(L, 0);
    for (int k = 1; k <= L - 1; k++) {
        int val = k;
        if (val > L - val) val = L - val;
        dists[k] = val;
    }

    vector<vector<int>> sp(L);
    vector<vector<long long>> cnt(L, vector<long long>(L + 1, 0));
    vector<long long> fact(L + 1, 1), invfact(L + 1, 1);

    for (int i = 1; i <= L; i++) fact[i] = (fact[i - 1] * i) % MOD;
    invfact[L] = modpow(fact[L], MOD - 2);
    for (int i = L; i >= 1; i--) invfact[i - 1] = (invfact[i] * i) % MOD;

    auto C = [&](int n, int r) -> long long {
        if (r < 0 || r > n) return 0LL;
        return (((fact[n] * invfact[r]) % MOD) * invfact[n - r]) % MOD;
    };

    int maxD = L / 2;

    auto count_max_le = [&](int D) -> long long {
        if (N == 1) return 1LL;
        if (D >= maxD) {
            return C(L, N);
        }
        int R = 2 * D;
        long long ans = 0;
        if (R == 0) return 0;
        int maxT = (L / R);
        for (int t = 1; t <= maxT; t++) {
            long long waysT = C(L - t * (R + 1) + t, t);
            long long waysComp = C(t - 1 + (N - t), N - t);
            ans += waysT * waysComp;
            ans %= MOD;
        }
        return ans;
    };

    auto count_max_le_fast = [&](int D) -> long long {
        if (N == 1) return 1LL;
        if (D >= maxD) return C(L, N);
        if (D < 1) return 0LL;

        int R = 2 * D;
        if (R <= 0) return 0LL;

        long long total = 0;
        for (int k = 1; k <= N; k++) {
            int sumMin = (k - 1) * (R + 1);
            int remaining = L - sumMin;
            if (remaining < k) continue;
            long long chooseSlots = C(remaining, k);
            long long choosePos = C(N - 1, k - 1);
            long long ways = chooseSlots * choosePos % MOD;
            total += ways;
            total %= MOD;
        }
        return total;
    };

    auto count_group_cost_eq = [&](int D) -> long long {
        long long leD = count_max_le_fast(D);
        long long lePrev = (D > 0) ? count_max_le_fast(D - 1) : 0;
        long long res = (leD - lePrev) % MOD;
        if (res < 0) res += MOD;
        return res;
    };

    long long result = 0;
    if (N == 1) {
        long long totalGroups = C(L, 1);
        long long sum = 0;
        result = 0;
        (void)totalGroups;
        cout << 0 << "\n";
        return 0;
    }

    for (int D = 1; D <= maxD; D++) {
        long long cntEq = count_group_cost_eq(D);
        result = (result + cntEq * (long long)D) % MOD;
    }

    cout << result % MOD << "\n";
    return 0;
}
/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

static const long long MOD = 1000000007LL;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k, d;
    if (!(cin >> n >> k >> d)) return 0;

    vector<long long> powk(n + 2, 1);
    for (int i = 1; i < (int)powk.size(); i++) powk[i] = (powk[i-1] * k) % MOD;

    vector<long long> f(k + 1, 0), g(k + 1, 0);
    f[d] = 1;
    for (int s = 0; s <= n; s++) {
        if (f[s] != 0) {
            int nd = min(n, s + k);
            (void)nd;
        }
    }

    vector<long long> dp(n + 1, 0), ndp(n + 1, 0);

    dp[0] = 1;
    for (int len = 1; len <= n; len++) {
        fill(ndp.begin(), ndp.end(), 0);
        for (int sum = 0; sum <= n; sum++) if (dp[sum]) {
            for (int w = 1; w <= k; w++) {
                if (sum + w <= n) {
                    ndp[sum + w] = (ndp[sum + w] + dp[sum]) % MOD;
                }
            }
        }
        dp.swap(ndp);
    }

    vector<long long> dpAll(n + 1, 0), dpStrict(n + 1, 0);
    dpAll[0] = 1;
    for (int i = 1; i <= n; i++) {
        dpAll[i] = 0;
    }
    vector<long long> curA(n + 1, 0), nxtA(n + 1, 0);
    vector<long long> curB(n + 1, 0), nxtB(n + 1, 0);
    curA[0] = 1;
    curB[0] = 1;

    for (int steps = 1; steps <= n; steps++) {
        fill(nxtA.begin(), nxtA.end(), 0);
        fill(nxtB.begin(), nxtB.end(), 0);
        for (int sum = 0; sum <= n; sum++) {
            if (curA[sum]) {
                for (int w = 1; w <= k; w++) {
                    if (sum + w <= n) nxtA[sum + w] = (nxtA[sum + w] + curA[sum]) % MOD;
                }
            }
            if (curB[sum]) {
                for (int w = d; w <= k; w++) {
                    if (sum + w <= n) nxtB[sum + w] = (nxtB[sum + w] + curB[sum]) % MOD;
                }
            }
        }
        curA.swap(nxtA);
        curB.swap(nxtB);
    }

    long long ans = curB[n] % MOD;
    cout << ans % MOD << "\n";
    return 0;
}
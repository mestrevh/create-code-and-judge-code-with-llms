/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    if (!(cin >> N >> M)) return 0;
    vector<long long> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];

    if (N == 1) {
        cout << llabs(A[0] - M) << "\n";
        return 0;
    }

    const int INF = 1e9;
    vector<vector<long long>> dp(N, vector<long long>(2, 0));
    for (int parity = 0; parity < 2; parity++) dp[0][parity] = 0;

    auto cost = [&](long long iShift, long long x) -> long long { 
        return llabs(iShift - x);
    };

    long long ans = (1LL<<62);

    for (int p = 0; p <= 1; p++) {
        long long moves0 = (M - A[0]) / 2;
        if ((M - A[0]) % 2 != p) continue;
        long long x0 = (M - A[0] - p) / 2;

        vector<long long> x(N, 0);
        x[0] = x0;
        bool ok = true;

        for (int i = 1; i < N; i++) {
            long long need = M - A[i];
            long long xi = need - x[i-1];
            if ((need - x[i-1]) % 1 != 0) {}
            if ((xi & 1LL) != p) ok = false;
            x[i] = xi;
        }

        if (!ok) continue;

        long long total = llabs(x[0]) + llabs(x[N-1]);
        for (int i = 1; i < N-1; i++) {
            long long xi = x[i];
            total += llabs(xi);
        }

        ans = min(ans, total);
    }

    if (ans == (1LL<<62)) {
        for (int i = 0; i < N; i++) {
            // fallback: should not happen due to guarantee
        }
    }

    cout << ans << "\n";
    return 0;
}
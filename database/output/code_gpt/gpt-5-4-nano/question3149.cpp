/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M, K;
    if (!(cin >> N >> M >> K)) return 0;

    const int MOD = 1000000007;

    vector<int> dp(N + 1, 0), ndp(N + 1, 0);
    dp[0] = 1;
    for (int i = 1; i <= M; i++) {
        long long window = 0;
        fill(ndp.begin(), ndp.end(), 0);
        for (int s = 0; s <= N; s++) {
            if (s - 1 >= 0) window += dp[s - 1];
            if (s - 1 - K >= 0) window -= dp[s - 1 - K];
            window %= MOD;
            if (window < 0) window += MOD;
            ndp[s] = (int)window;
        }
        dp.swap(ndp);
    }

    cout << dp[N] % MOD << "\n";
    return 0;
}
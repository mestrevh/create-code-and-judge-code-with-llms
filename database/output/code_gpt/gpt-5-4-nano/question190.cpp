/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long N, K;
    if (!(cin >> N >> K)) return 0;

    if (K == 1) {
        cout << N << "\n";
        return 0;
    }

    vector<unsigned long long> dp((size_t)K + 1, 0);
    unsigned long long ans = 0;

    while (dp[K] < (unsigned long long)N) {
        ans++;
        for (long long k = K; k >= 1; --k) {
            unsigned long long add = dp[k - 1] + 1;
            unsigned long long val = dp[k] + add;
            if (val < dp[k]) val = ULLONG_MAX;
            dp[k] = val;
        }
    }

    cout << ans << "\n";
    return 0;
}
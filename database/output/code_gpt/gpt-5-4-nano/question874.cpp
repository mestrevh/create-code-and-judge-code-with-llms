/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    while (cin >> n) {
        if (n == 0) break;
        vector<long long> price(n + 1, 0);
        for (int i = 1; i <= n; i++) cin >> price[i];

        vector<long long> dp(n + 1, 0);
        for (int i = 1; i <= n; i++) {
            long long best = price[i];
            for (int j = 1; j < i; j++) {
                best = max(best, dp[j] + dp[i - j]);
            }
            dp[i] = best;
        }

        cout << dp[n] << "\n";
    }
    return 0;
}
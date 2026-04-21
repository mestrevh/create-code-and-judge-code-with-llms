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
    while ( (cin >> n) ) {
        vector<long long> p(n);
        for (int i = 0; i < n; i++) cin >> p[i];

        if (n == 0) {
            cout << 0 << "\n";
            continue;
        }

        vector<long long> dp(n, 0), ndp(n, 0);

        for (int i = 0; i < n; i++) dp[i] = p[i] * n;

        for (int len = n - 1; len >= 1; --len) {
            int year = n - len + 1;
            for (int l = 0; l + len - 1 < n; ++l) {
                int r = l + len - 1;
                long long left = p[l] * year + dp[l + 1];
                long long right = p[r] * year + dp[l];
                ndp[l] = max(left, right);
            }
            dp.swap(ndp);
        }

        long long ans = dp[0];
        cout << ans << "\n";
    }
    return 0;
}
/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    const int MAXN = 999999;
    vector<int> dp(MAXN + 1, 0);

    dp[1] = 1;

    auto cycleSize = [&](int n) -> int {
        int original = n;
        vector<int> path;
        while (true) {
            if (n <= MAXN && dp[n] != 0) {
                int acc = dp[n];
                for (int k = (int)path.size() - 1; k >= 0; --k) {
                    acc += 1;
                    dp[path[k]] = acc;
                }
                return dp[original];
            }
            path.push_back(n);
            if (n % 2 == 0) n /= 2;
            else n = 3 * n + 1;
        }
    };

    long long i, j;
    while (cin >> i >> j) {
        int a = (int)i, b = (int)j;
        if (a > b) swap(a, b);
        int ans = 0;
        for (int x = a; x <= b; ++x) {
            ans = max(ans, cycleSize(x));
        }
        cout << i << " " << j << " " << ans << "\n";
    }
    return 0;
}
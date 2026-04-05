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
    if (!(cin >> n)) return 0;

    vector<unsigned long long> dp(n + 1, 0);
    vector<char> vis(n + 1, 0);

    function<unsigned long long(int)> calc = [&](int k) -> unsigned long long {
        if (k <= 0) return 0;
        if (k == 1 || k == 2) return 1;
        if (k >= 1 && k < (int)dp.size() && vis[k]) return dp[k];
        unsigned long long a = calc(k - 1);
        unsigned long long b = calc(k - 2);
        unsigned long long c = a + b;
        if (k < (int)dp.size()) {
            dp[k] = c;
            vis[k] = 1;
        }
        return c;
    };

    for (int i = 1; i <= n; i++) {
        cout << calc(i) << "\n";
    }
    return 0;
}
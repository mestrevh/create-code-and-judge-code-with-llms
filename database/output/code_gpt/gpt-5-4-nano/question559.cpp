/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    if (!(cin >> T)) return 0;
    while (T--) {
        int n;
        cin >> n;
        vector<int> dp(31, 0);
        vector<int> bestG(31, 0);

        for (int i = 0; i < n; i++) {
            int p, w;
            cin >> p >> w;
            for (int c = 30; c >= w; c--) {
                dp[c] = max(dp[c], dp[c - w] + p);
            }
        }

        for (int c = 0; c <= 30; c++) bestG[c] = dp[c];

        int g;
        cin >> g;
        long long ans = 0;
        for (int i = 0; i < g; i++) {
            int m;
            cin >> m;
            ans += bestG[m];
        }
        cout << ans << "\n";
    }
    return 0;
}
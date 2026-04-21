/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int EV1, EV2, AT, D;
    while (cin >> EV1 >> EV2 >> AT >> D) {
        if (EV1 == 0 && EV2 == 0 && AT == 0 && D == 0) break;

        double p1 = max(0, min(6, AT)) / 6.0;
        double p2 = 1.0 - p1;

        int maxE = EV1 + EV2 + D + 1;
        vector<vector<double>> dp(maxE + 1, vector<double>(maxE + 1, 0.0));
        vector<vector<char>> vis(maxE + 1, vector<char>(maxE + 1, 0));

        auto solve = [&](auto&& self, int a, int b) -> double {
            if (a <= 0) return 0.0;
            if (b <= 0) return 1.0;
            if (vis[a][b]) return dp[a][b];
            vis[a][b] = 1;
            dp[a][b] = p1 * self(self, a - D, b + D) + p2 * self(self, a + D, b - D);
            return dp[a][b];
        };

        double ans = solve(solve, EV1, EV2) * 100.0;
        cout.setf(std::ios::fixed); 
        cout << setprecision(1) << ans + 1e-9 << "\n";
    }
    return 0;
}
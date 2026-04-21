/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, G;
    if (!(cin >> N >> G)) return 0;

    vector<int> diff(N);
    int basePoints = 0;
    for (int i = 0; i < N; i++) {
        int S, R;
        cin >> S >> R;
        diff[i] = S - R;
        if (S > R) basePoints += 3;
        else if (S == R) basePoints += 1;
    }

    const int NEG = -1e9;
    vector<vector<int>> dp(N + 1, vector<int>(G + 1, NEG));
    dp[0][G] = basePoints;

    for (int i = 0; i < N; i++) {
        vector<vector<int>> ndp(N + 1, vector<int>(G + 1, NEG));
        for (int t = 0; t <= G; t++) {
            ndp[i][t] = dp[i][t];
        }
        for (int used = 0; used <= G; used++) {
            int cur = dp[i][used];
            if (cur == NEG) continue;
            int remaining = G - used;

            int d = diff[i];

            if (d > 0) {
                ndp[i + 1][used] = max(ndp[i + 1][used], cur);
                if (remaining >= 1) ndp[i + 1][used + 1] = max(ndp[i + 1][used + 1], cur + 0);
            } else if (d == 0) {
                ndp[i + 1][used] = max(ndp[i + 1][used], cur);
                if (remaining >= 1) ndp[i + 1][used + 1] = max(ndp[i + 1][used + 1], cur + 2);
            } else {
                int needWin = -d + 1;
                if (needWin <= remaining) ndp[i + 1][used + needWin] = max(ndp[i + 1][used + needWin], cur + 3);
                int needDraw = -d;
                if (needDraw <= remaining) ndp[i + 1][used + needDraw] = max(ndp[i + 1][used + needDraw], cur + 1);
                ndp[i + 1][used] = max(ndp[i + 1][used], cur);
            }
        }
        for (int used = 0; used <= G; used++) dp[i + 1][used] = ndp[i + 1][used];
    }

    int ans = 0;
    for (int used = 0; used <= G; used++) ans = max(ans, dp[N][used]);
    cout << ans << "\n";
    return 0;
}
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

    int rows = N, cols = M;
    if (rows < cols) swap(rows, cols);

    int maxMask = 1 << cols;

    vector<int> dp(maxMask, -1), ndp(maxMask, -1);
    dp[0] = 0;

    for (int r = 0; r < rows; r++) {
        fill(ndp.begin(), ndp.end(), -1);
        for (int mask = 0; mask < maxMask; mask++) {
            if (dp[mask] < 0) continue;
            function<void(int,int,int)> dfs = [&](int c, int curMask, int add) {
                if (c == cols) {
                    ndp[curMask] = max(ndp[curMask], dp[mask] + add);
                    return;
                }
                if (curMask & (1 << c)) {
                    dfs(c + 1, curMask, add);
                    return;
                }

                if (c + 1 < cols && !(curMask & (1 << (c + 1)))) {
                    int nmask = curMask | (1 << c) | (1 << (c + 1));
                    dfs(c + 2, nmask, add + 1);
                }

                if (r + 1 < rows) {
                    int nmask = curMask | (1 << c);
                    dfs(c + 1, nmask, add + 1);
                }

                dfs(c + 1, curMask | (1 << c), add);
            };

            int startMask = mask;
            dfs(0, startMask, 0);
        }

        dp.swap(ndp);
    }

    int ans = 0;
    for (int mask = 0; mask < maxMask; mask++) ans = max(ans, dp[mask]);
    cout << ans << "\n";
    return 0;
}
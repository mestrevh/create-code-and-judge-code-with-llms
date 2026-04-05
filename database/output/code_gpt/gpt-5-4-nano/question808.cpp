/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int K;
    if (!(cin >> K)) return 0;
    for (int tc = 0; tc < K; tc++) {
        int L;
        cin >> L;
        vector<int> P(L);
        for (int i = 0; i < L; i++) cin >> P[i];
        int M;
        long long Q;
        cin >> M >> Q;

        vector<vector<long long>> ways(L + 1);
        vector<long long> dp(Q + 1, 0);

        dp[0] = 1;
        for (int i = 0; i < L; i++) {
            vector<long long> ndp(Q + 1, 0);
            int price = P[i];
            for (long long s = 0; s <= Q; s++) {
                if (!dp[s]) continue;
                ndp[s] += dp[s];
                if (s + price <= Q) ndp[s + price] += dp[s];
            }
            dp.swap(ndp);
        }

        long long ans = 0;
        for (int i = 0; i < L; i++) { (void)i; }

        vector<vector<long long>> dp2(M + 1, vector<long long>(Q + 1, 0));
        dp2[0][0] = 1;
        for (int i = 0; i < L; i++) {
            int price = P[i];
            auto ndp2 = dp2;
            for (int cnt = 0; cnt <= M; cnt++) {
                for (long long s = 0; s + price <= Q; s++) {
                    long long val = dp2[cnt][s];
                    if (!val) continue;
                    int ncnt = min(M, cnt + 1);
                    ndp2[ncnt][s + price] += val;
                }
            }
            dp2.swap(ndp2);
        }

        for (long long s = 0; s <= Q; s++) ans += dp2[M][s];

        cout << "caso " << tc << ": " << ans << "\n";
    }
    return 0;
}
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
    for (int tc = 1; tc <= T; tc++) {
        int N, M;
        cin >> N >> M;
        vector<int> a(N + 1);
        for (int i = 1; i <= N; i++) cin >> a[i];

        vector<pair<int,int>> queries(M);
        vector<int> X(M), K(M);
        for (int j = 0; j < M; j++) {
            cin >> X[j] >> K[j];
        }

        int Q = 0;
        vector<int> maxNeed(N + 1, 0);
        for (int j = 0; j < M; j++) {
            if (K[j] > 0) maxNeed[X[j]] = max(maxNeed[X[j]], K[j]);
            Q = max(Q, X[j]);
        }

        int B = 1;
        while (B <= 100000) B <<= 1;
        int S = B * 2; 
        vector<int> dp(S, 0), ndp(S, 0);
        dp[0] = 1;

        vector<vector<pair<int,int>>> byX(N + 1);
        byX.assign(N + 1, {});
        for (int j = 0; j < M; j++) {
            byX[X[j]].push_back({K[j], j});
        }

        vector<int> ans(M, 0);

        for (int i = 1; i <= N; i++) {
            int w = a[i];
            if (w < S) {
                for (int s = S - 1; s >= w; s--) {
                    if (dp[s - w]) dp[s] = 1;
                }
            }
            for (auto &pr : byX[i]) {
                int k = pr.first;
                int idx = pr.second;
                if (k < S && dp[k]) ans[idx] = 1;
            }
        }

        cout << "caso " << tc << ":";
        for (int j = 0; j < M; j++) cout << " " << ans[j];
        cout << "\n";
    }
    return 0;
}
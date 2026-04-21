/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

struct Seg {
    int s, e;
    long long v;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int K;
    if (!(cin >> K)) return 0;

    for (int tc = 1; tc <= K; tc++) {
        int N;
        cin >> N;
        vector<Seg> a(N);
        for (int i = 0; i < N; i++) {
            cin >> a[i].s >> a[i].e >> a[i].v;
        }

        vector<int> coords;
        coords.reserve(2 * N + 2);
        for (auto &x : a) {
            coords.push_back(x.s);
            coords.push_back(x.e + 1);
        }
        coords.push_back(1);
        coords.push_back(3650 + 2);
        sort(coords.begin(), coords.end());
        coords.erase(unique(coords.begin(), coords.end()), coords.end());

        int M = (int)coords.size();
        const long long NEG = -(1LL<<60);

        vector<long long> dp(M, 0);
        for (int i = 0; i < M; i++) dp[i] = 0;

        vector<vector<int>> at(M);
        for (int i = 0; i < N; i++) {
            int idxS = (int)(lower_bound(coords.begin(), coords.end(), a[i].s) - coords.begin());
            int idxE1 = (int)(lower_bound(coords.begin(), coords.end(), a[i].e + 1) - coords.begin());
            at[idxE1].push_back(i);
        }

        vector<vector<int>> startAt(M);
        for (int i = 0; i < N; i++) {
            int idxS = (int)(lower_bound(coords.begin(), coords.end(), a[i].s) - coords.begin());
            startAt[idxS].push_back(i);
        }

        for (int i = 0; i < M; i++) {
            if (i) dp[i] = max(dp[i], dp[i-1]);
            for (int idx : startAt[i]) {
                int idxE1 = (int)(lower_bound(coords.begin(), coords.end(), a[idx].e + 1) - coords.begin());
                long long cand = dp[i] + a[idx].v;
                dp[idxE1] = max(dp[idxE1], cand);
            }
        }

        long long ans = 0;
        for (int i = 0; i < M; i++) ans = max(ans, dp[i]);

        cout << "caso " << tc << ": " << ans << "\n\n";
    }
    return 0;
}
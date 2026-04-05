/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, Q;
    int tc = 0;
    while ( (cin >> N >> Q) ) {
        if (N == 0 && Q == 0) break;
        tc++;

        vector<long long> a(N);
        for (int i = 0; i < N; i++) cin >> a[i];

        vector<pair<int,int>> queries(Q);
        for (int i = 0; i < Q; i++) {
            int D, M;
            cin >> D >> M;
            queries[i] = {D, M};
        }

        cout << "SET " << tc << ":\n";

        const int DMAX = 20;
        const int MMAX = 10;

        vector<vector<long long>> fact(DMAX + 1, vector<long long>(MMAX + 1, 1));
        for (int d = 1; d <= DMAX; d++) {
            for (int m = 1; m <= MMAX; m++) fact[d][m] = fact[d][m-1] * (long long)m;
        }

        vector<vector<array<long long, MMAX + 1>>> poly(DMAX + 1, vector<array<long long, MMAX + 1>>(DMAX + 1));
        for (int d = 1; d <= DMAX; d++) {
            for (int r = 0; r < d; r++) {
                array<long long, MMAX + 1> arr{};
                arr.fill(0);
                poly[d][r] = arr;
            }
            for (int r = 0; r < d; r++) poly[d][r].fill(0);
        }

        vector<unordered_map<int, vector<array<long long, MMAX + 1>>>> computed(21);

        for (int qi = 0; qi < Q; qi++) {
            int D = queries[qi].first;
            int M = queries[qi].second;

            auto &store = computed[D];
            if (store.empty()) {
                vector<array<long long, MMAX + 1>> dp(D);
                for (int r = 0; r < D; r++) {
                    dp[r].fill(0);
                }
                dp[0][0] = 1;

                for (int i = 0; i < N; i++) {
                    int rem = (int)((a[i] % D + D) % D);
                    vector<array<long long, MMAX + 1>> ndp = dp;
                    for (int r = 0; r < D; r++) {
                        if (dp[r][0] == 0 && dp[r][1] == 0 && dp[r][2] == 0 && dp[r][3] == 0 &&
                            dp[r][4] == 0 && dp[r][5] == 0 && dp[r][6] == 0 && dp[r][7] == 0 &&
                            dp[r][8] == 0 && dp[r][9] == 0 && dp[r][10] == 0) {
                            continue;
                        }
                        int nr = (r + rem) % D;
                        for (int k = 0; k < MMAX; k++) {
                            if (dp[r][k] != 0) ndp[nr][k+1] += dp[r][k];
                        }
                    }
                    dp.swap(ndp);
                }

                store[D] = dp;
            }

            long long ans = computed[D][D][0][0];
            auto &dp = computed[D][D];
            if (M >= 0 && M <= MMAX) {
                long long res = dp[0][M];
                cout << "QUERY " << (qi + 1) << ": " << res << "\n";
            } else {
                cout << "QUERY " << (qi + 1) << ": 0\n";
            }
        }
    }
    return 0;
}
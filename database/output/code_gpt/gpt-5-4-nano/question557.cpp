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
    int tc = 1;
    while ( (cin >> n) ) {
        if (n == 0) break;

        vector<pair<int,int>> dims(n);
        for (int i = 0; i < n; i++) {
            int r, c;
            cin >> r >> c;
            dims[i] = {r, c};
        }

        vector<long long> p(n + 1);
        for (int i = 0; i < n; i++) p[i] = dims[i].first;
        p[n] = dims[n-1].second;

        const long long INF = (1LL<<62);
        vector<vector<long long>> dp(n, vector<long long>(n, 0));
        vector<vector<int>> split(n, vector<int>(n, -1));

        for (int len = 2; len <= n; len++) {
            for (int i = 0; i + len - 1 < n; i++) {
                int j = i + len - 1;
                dp[i][j] = INF;
                for (int k = i; k < j; k++) {
                    long long cost = dp[i][k] + dp[k+1][j] + p[i]*p[k+1]*p[j+1];
                    if (cost < dp[i][j]) {
                        dp[i][j] = cost;
                        split[i][j] = k;
                    }
                }
            }
        }

        function<string(int,int)> build = [&](int i, int j) -> string {
            if (i == j) return "A" + to_string(i+1);
            int k = split[i][j];
            return "(" + build(i, k) + " x " + build(k+1, j) + ")";
        };

        cout << "Case " << tc++ << ": " << build(0, n-1) << "\n";
    }

    return 0;
}
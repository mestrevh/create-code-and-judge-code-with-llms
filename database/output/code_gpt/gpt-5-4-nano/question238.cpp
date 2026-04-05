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
    vector<vector<long long>> c(n, vector<long long>(n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> c[i][j];

    const long long INF = (1LL<<62);
    vector<vector<long long>> dp(n, vector<long long>(n, INF));
    vector<vector<int>> parent(n, vector<int>(n, -1));

    for (int j = 0; j < n; j++) dp[0][j] = c[0][j];

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < n; j++) {
            long long best = INF;
            int bestPrev = -1;
            for (int dj : {-1, 0, 1}) {
                int pj = j + dj;
                if (pj < 0 || pj >= n) continue;
                long long cand = dp[i-1][pj] + c[i][j];
                if (cand < best) {
                    best = cand;
                    bestPrev = pj;
                }
            }
            dp[i][j] = best;
            parent[i][j] = bestPrev;
        }
    }

    long long ans = INF;
    int endj = 0;
    for (int j = 0; j < n; j++) {
        if (dp[n-1][j] < ans) {
            ans = dp[n-1][j];
            endj = j;
        }
    }

    cout << ans << "\n";

    vector<pair<int,int>> path;
    int i = n - 1, j = endj;
    while (true) {
        path.push_back({i, j});
        if (i == 0) break;
        j = parent[i][j];
        i--;
    }

    for (size_t k = 0; k < path.size(); k++) {
        auto [ri, rj] = path[k];
        cout << "[" << ri << "," << rj << "]";
        if (k + 1 < path.size()) cout << " <- ";
    }
    cout << "\n";

    return 0;
}
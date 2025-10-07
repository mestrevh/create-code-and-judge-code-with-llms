/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>

using namespace std;

int maxCongressistas(int D, int P, int R, int B, vector<int> &cost_d, vector<int> &cost_p, vector<pair<int, int>> &rivalries) {
    vector<vector<bool>> graph(D + 1, vector<bool>(P + 1, true));
    for (auto &rivalry : rivalries) {
        graph[rivalry.first][rivalry.second] = false;
        graph[rivalry.second][rivalry.first] = false;
    }
    
    int max_dp = 0, max_prism = 0;
    vector<int> dp(B + 1, 0);
    dp[0] = 0;

    for (int i = 1; i <= D; ++i) {
        for (int j = B; j >= cost_d[i - 1]; --j) {
            dp[j] = max(dp[j], dp[j - cost_d[i - 1]] + 1);
        }
    }

    max_dp = dp[B];

    vector<int> dp_p(B + 1, 0);
    dp_p[0] = 0;

    for (int i = 1; i <= P; ++i) {
        for (int j = B; j >= cost_p[i - 1]; --j) {
            dp_p[j] = max(dp_p[j], dp_p[j - cost_p[i - 1]] + 1);
        }
    }

    max_prism = dp_p[B];

    for (int i = 1; i <= D; ++i) {
        for (int j = 1; j <= P; ++j) {
            if (!graph[i][j]) continue;
            for (int k = B; k >= cost_d[i - 1] + cost_p[j - 1]; --k) {
                dp[k] = max(dp[k], dp[k - cost_d[i - 1]] + 1 + dp_p[k - cost_p[j - 1]]);
            }
        }
    }

    return {max_dp, max_prism};
}

int main() {
    int D, P, R, B;
    cin >> D >> P >> R >> B;
    
    vector<int> cost_d(D), cost_p(P);
    for (int i = 0; i < D; ++i) cin >> cost_d[i];
    for (int i = 0; i < P; ++i) cin >> cost_p[i];

    vector<pair<int, int>> rivalries(R);
    for (int i = 0; i < R; ++i) {
        int x, y;
        cin >> x >> y;
        rivalries[i] = {x, y};
    }

    auto result = maxCongressistas(D, P, R, B, cost_d, cost_p, rivalries);
    cout << result.first << " " << result.second << endl;

    return 0;
}

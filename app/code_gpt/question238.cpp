/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<vector<int>> cost(n, vector<int>(n));
    vector<vector<int>> dp(n, vector<int>(n));
    vector<vector<int>> path(n, vector<int>(n, -1));

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            cin >> cost[i][j];

    for (int j = 0; j < n; ++j)
        dp[0][j] = cost[0][j];

    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            for (int k = j - 1; k <= j + 1; ++k) {
                if (k >= 0 && k < n) {
                    if (dp[i][j] > dp[i - 1][k] + cost[i][j]) {
                        dp[i][j] = dp[i - 1][k] + cost[i][j];
                        path[i][j] = k;
                    }
                }
            }
        }
    }

    int min_cost = INT_MAX, min_index = -1;
    for (int j = 0; j < n; ++j) {
        if (dp[n - 1][j] < min_cost) {
            min_cost = dp[n - 1][j];
            min_index = j;
        }
    }

    cout << min_cost << endl;

    vector<pair<int, int>> result;
    for (int i = n - 1; i >= 0; --i) {
        result.emplace_back(i, min_index);
        min_index = path[i][min_index];
    }

    for (int i = result.size() - 1; i > 0; --i)
        cout << "[" << result[i].first << "," << result[i].second << "] <- ";
    cout << "[" << result[0].first << "," << result[0].second << "]" << endl;

    return 0;
}

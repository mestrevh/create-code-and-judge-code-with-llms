/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;

    if (n <= 0) return 0;

    vector<vector<long long>> cost(n, vector<long long>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> cost[i][j];
        }
    }

    vector<vector<long long>> dp(n, vector<long long>(n));
    vector<vector<int>> parent(n, vector<int>(n));

    for (int j = 0; j < n; ++j) {
        dp[0][j] = cost[0][j];
    }

    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            int best_k = -1;
            for (int k = j - 1; k <= j + 1; ++k) {
                if (k >= 0 && k < n) {
                    if (best_k == -1 || dp[i - 1][k] < dp[i - 1][best_k]) {
                        best_k = k;
                    }
                }
            }
            dp[i][j] = cost[i][j] + dp[i - 1][best_k];
            parent[i][j] = best_k;
        }
    }

    long long min_total = dp[n - 1][0];
    int cur_j = 0;
    for (int j = 1; j < n; ++j) {
        if (dp[n - 1][j] < min_total) {
            min_total = dp[n - 1][j];
            cur_j = j;
        }
    }

    cout << min_total << "\n";
    for (int i = n - 1; i >= 0; --i) {
        cout << "[" << i << "," << cur_j << "]";
        if (i > 0) {
            cout << " <- ";
            cur_j = parent[i][cur_j];
        }
    }
    cout << endl;

    return 0;
}
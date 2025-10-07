/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

const long long INF = 1e18;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int a, n;
    long long c;

    cin >> a;
    cin >> n;
    cin >> c;

    vector<long long> manut(n + 2);
    for (int i = 0; i <= n + 1; ++i) {
        cin >> manut[i];
    }

    vector<long long> venda(n + 2, 0);
    for (int i = 1; i <= n + 1; ++i) {
        cin >> venda[i];
    }

    vector<long long> sucata(n + 2, 0);
    for (int i = 1; i <= n + 1; ++i) {
        cin >> sucata[i];
    }

    vector<vector<long long>> dp(n + 2, vector<long long>(n + 2, INF));
    vector<vector<int>> parent(n + 2, vector<int>(n + 2, -1));

    if (a <= n + 1) {
        dp[1][a] = 0;
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j <= n + 1; ++j) {
            if (dp[i][j] == INF) {
                continue;
            }

            // Option 1: Maintain
            int next_age_m = j + 1;
            if (next_age_m <= n + 1) {
                long long cost_m = dp[i][j] + manut[j];
                if (cost_m < dp[i + 1][next_age_m]) {
                    dp[i + 1][next_age_m] = cost_m;
                    parent[i + 1][next_age_m] = j;
                }
            }

            // Option 2: Buy
            int next_age_b = 0;
            if (j + 1 <= n + 1) {
                long long cost_b = dp[i][j] + manut[j] + c - venda[j + 1];
                if (cost_b < dp[i + 1][next_age_b]) {
                    dp[i + 1][next_age_b] = cost_b;
                    parent[i + 1][next_age_b] = j;
                }
            }
        }
    }

    long long min_total_cost = INF;
    int final_age = -1;

    for (int j = 1; j <= n + 1; ++j) {
        if (dp[n + 1][j] != INF) {
            long long current_cost = dp[n + 1][j] - sucata[j];
            if (current_cost < min_total_cost) {
                min_total_cost = current_cost;
                final_age = j;
            }
        }
    }

    cout << min_total_cost << endl;

    string result = "";
    int current_age = final_age;

    for (int i = n + 1; i >= 2; --i) {
        int prev_age = parent[i][current_age];
        if (current_age == 0) {
            result += 'B';
        } else {
            result += 'M';
        }
        current_age = prev_age;
    }

    reverse(result.begin(), result.end());
    cout << result << endl;

    return 0;
}

/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    int a, n, c;
    cin >> a >> n >> c;

    vector<int> maintenance(n + 2), sell(n + 1), scrap(n + 1);
    for (int i = 0; i <= n + 1; ++i) cin >> maintenance[i];
    for (int i = 1; i <= n + 1; ++i) cin >> sell[i];
    for (int i = 1; i <= n + 1; ++i) cin >> scrap[i];

    vector<vector<long long>> dp(n + 2, vector<long long>(2, LLONG_MAX));
    vector<vector<int>> choice(n + 2, vector<int>(2, -1));

    dp[a][0] = 0; // Manter

    for (int year = 1; year <= n; ++year) {
        for (int age = 0; age <= n + 1; ++age) {
            if (dp[age][0] != LLONG_MAX) {
                long long cost = dp[age][0] + maintenance[age + 1];
                if (cost < dp[age + 1][0]) {
                    dp[age + 1][0] = cost;
                    choice[age + 1][0] = 0;
                }
            }
            if (age > 0 && dp[age][1] != LLONG_MAX) {
                long long cost = dp[age][1] + maintenance[age + 1];
                if (cost < dp[age + 1][0]) {
                    dp[age + 1][0] = cost;
                    choice[age + 1][0] = 1;
                }
            }

            long long buy_cost = (dp[age][0] != LLONG_MAX) ? dp[age][0] + c - scrap[age] : LLONG_MAX;
            if (buy_cost < dp[0][1]) {
                dp[0][1] = buy_cost;
                choice[0][1] = 0;
            }
            buy_cost = (dp[age][1] != LLONG_MAX) ? dp[age][1] + c - scrap[age] : LLONG_MAX;
            if (buy_cost < dp[0][1]) {
                dp[0][1] = buy_cost;
                choice[0][1] = 1;
            }
        }
    }

    long long min_cost = LLONG_MAX;
    int best_choice = -1;
    for (int age = 0; age <= n + 1; ++age) {
        if (dp[age][0] < min_cost) {
            min_cost = dp[age][0];
            best_choice = 0;
        }
        if (dp[age][1] < min_cost) {
            min_cost = dp[age][1];
            best_choice = 1;
        }
    }

    string decisions;
    int current_age = best_choice == 0 ? a : 0;

    for (int year = 1; year <= n; ++year) {
        if (choice[current_age][best_choice] == 0) {
            decisions += 'M';
            current_age++;
        } else {
            decisions += 'B';
            current_age = 0;
        }
    }

    cout << min_cost << endl;
    cout << decisions << endl;

    return 0;
}

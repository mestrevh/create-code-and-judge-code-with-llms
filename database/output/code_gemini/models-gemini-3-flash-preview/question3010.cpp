/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    if (!(cin >> n >> m)) return 0;

    vector<vector<char>> grid(n, vector<char>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (!(cin >> grid[i][j])) break;
        }
    }

    vector<vector<long long>> dp(n, vector<long long>(m, -1));
    long long global_max_coins = 0;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (grid[i][j] == '|') continue;

            int current_cell_value = 0;
            if (grid[i][j] == 'o') {
                current_cell_value = 1;
            } else if (grid[i][j] == '8') {
                current_cell_value = 2;
            }

            if (i == 0 && j == 0) {
                dp[i][j] = (long long)current_cell_value;
            } else {
                long long max_from_prev = -1;
                if (i > 0) {
                    if (dp[i - 1][j] > max_from_prev) {
                        max_from_prev = dp[i - 1][j];
                    }
                }
                if (j > 0) {
                    if (dp[i][j - 1] > max_from_prev) {
                        max_from_prev = dp[i][j - 1];
                    }
                }

                if (max_from_prev != -1) {
                    dp[i][j] = max_from_prev + (long long)current_cell_value;
                }
            }

            if (dp[i][j] != -1) {
                if (dp[i][j] > global_max_coins) {
                    global_max_coins = dp[i][j];
                }
            }
        }
    }

    if (dp[n - 1][m - 1] != -1) {
        cout << "SIM" << endl;
    } else {
        cout << "NAO" << endl;
    }

    cout << "Valor maximo de moedas: " << global_max_coins << endl;

    return 0;
}
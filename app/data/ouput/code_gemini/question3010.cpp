/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int get_coins(char c) {
    if (c == 'o') return 1;
    if (c == '8') return 2;
    return 0;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n, m;
    std::cin >> n >> m;

    std::vector<std::string> grid(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> grid[i];
    }

    std::vector<std::vector<int>> dp(n, std::vector<int>(m, -1));

    if (grid[0][0] != '|') {
        dp[0][0] = get_coins(grid[0][0]);
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (grid[i][j] == '|') {
                continue;
            }
            if (i > 0 && dp[i-1][j] != -1) {
                int score = dp[i-1][j] + get_coins(grid[i][j]);
                if (score > dp[i][j]) {
                    dp[i][j] = score;
                }
            }
            if (j > 0 && dp[i][j-1] != -1) {
                int score = dp[i][j-1] + get_coins(grid[i][j]);
                if (score > dp[i][j]) {
                    dp[i][j] = score;
                }
            }
        }
    }

    if (dp[n-1][m-1] != -1) {
        std::cout << "SIM\n";
    } else {
        std::cout << "NAO\n";
    }

    int max_coins = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (dp[i][j] > max_coins) {
                max_coins = dp[i][j];
            }
        }
    }
    
    std::cout << "Valor maximo de moedas: " << max_coins << "\n";

    return 0;
}

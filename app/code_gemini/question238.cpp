/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;

    if (n <= 0) {
        return 0;
    }

    std::vector<std::vector<int>> cost(n, std::vector<int>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            std::cin >> cost[i][j];
        }
    }

    std::vector<std::vector<long long>> dp(n, std::vector<long long>(n));
    std::vector<std::vector<int>> parent(n, std::vector<int>(n));

    for (int j = 0; j < n; ++j) {
        dp[0][j] = cost[0][j];
        parent[0][j] = -1;
    }

    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            long long min_prev_dp = dp[i - 1][j];
            int p_col = j;

            if (j > 0 && dp[i - 1][j - 1] < min_prev_dp) {
                min_prev_dp = dp[i - 1][j - 1];
                p_col = j - 1;
            }

            if (j < n - 1 && dp[i - 1][j + 1] < min_prev_dp) {
                min_prev_dp = dp[i - 1][j + 1];
                p_col = j + 1;
            }

            dp[i][j] = cost[i][j] + min_prev_dp;
            parent[i][j] = p_col;
        }
    }

    long long min_total_cost = LLONG_MAX;
    int end_col = -1;
    for (int j = 0; j < n; ++j) {
        if (dp[n - 1][j] < min_total_cost) {
            min_total_cost = dp[n - 1][j];
            end_col = j;
        }
    }

    std::cout << min_total_cost << std::endl;

    std::vector<std::pair<int, int>> path;
    int current_col = end_col;
    for (int i = n - 1; i >= 0; --i) {
        path.push_back({i, current_col});
        if (i > 0) {
            current_col = parent[i][current_col];
        }
    }

    for (size_t k = 0; k < path.size(); ++k) {
        std::cout << "[" << path[k].first << "," << path[k].second << "]";
        if (k < path.size() - 1) {
            std::cout << " <- ";
        }
    }
    std::cout << std::endl;

    return 0;
}

/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n, m, k;
    std::cin >> n >> m >> k;

    const int MOD = 1e9 + 7;

    std::vector<std::vector<long long>> dp(m + 1, std::vector<long long>(n + 1, 0));

    dp[0][0] = 1;

    for (int i = 1; i <= m; ++i) {
        std::vector<long long> prefix_sum(n + 1, 0);
        prefix_sum[0] = dp[i - 1][0];
        for (int j = 1; j <= n; ++j) {
            prefix_sum[j] = (prefix_sum[j - 1] + dp[i - 1][j]) % MOD;
        }

        for (int j = 1; j <= n; ++j) {
            int upper_idx = j - 1;
            int lower_idx = j - k;

            if (upper_idx < 0) continue;

            long long upper_sum = prefix_sum[upper_idx];
            long long lower_sum_sub = (lower_idx - 1 >= 0) ? prefix_sum[lower_idx - 1] : 0;
            
            dp[i][j] = (upper_sum - lower_sum_sub + MOD) % MOD;
        }
    }

    std::cout << dp[m][n] << std::endl;

    return 0;
}

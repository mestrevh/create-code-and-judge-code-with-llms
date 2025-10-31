/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <cstring>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n, q;
    int case_num = 1;

    while (std::cin >> n >> q && (n != 0 || q != 0)) {
        std::cout << "SET " << case_num++ << ":" << std::endl;

        std::vector<int> nums(n);
        for (int i = 0; i < n; ++i) {
            std::cin >> nums[i];
        }

        for (int query_num = 1; query_num <= q; ++query_num) {
            int d, m;
            std::cin >> d >> m;

            long long dp[m + 1][d];
            std::memset(dp, 0, sizeof(dp));
            dp[0][0] = 1;

            for (int val : nums) {
                int rem = (val % d + d) % d;
                for (int i = m; i >= 1; --i) {
                    for (int j = 0; j < d; ++j) {
                        int prev_rem = (j - rem + d) % d;
                        dp[i][j] += dp[i - 1][prev_rem];
                    }
                }
            }

            std::cout << "QUERY " << query_num << ": " << dp[m][0] << std::endl;
        }
    }

    return 0;
}

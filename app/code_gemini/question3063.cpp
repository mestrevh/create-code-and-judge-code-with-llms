/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>

const int MOD = 1000000007;

long long count_ways(int n, int max_w) {
    std::vector<long long> dp(n + 1, 0);
    dp[0] = 1;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= max_w; ++j) {
            if (i >= j) {
                dp[i] = (dp[i] + dp[i - j]) % MOD;
            }
        }
    }
    return dp[n];
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n, k, d;
    std::cin >> n >> k >> d;

    long long total_paths = count_ways(n, k);
    long long bad_paths = count_ways(n, d - 1);

    long long result = (total_paths - bad_paths + MOD) % MOD;

    std::cout << result << std::endl;

    return 0;
}

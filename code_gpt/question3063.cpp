/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>

const int MOD = 1000000007;

int main() {
    int n, k, d;
    std::cin >> n >> k >> d;

    std::vector<long long> dp(n + 1, 0);
    std::vector<long long> dp_with_d(n + 1, 0);

    dp[0] = 1; 
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= k; ++j) {
            if (i - j >= 0) {
                dp[i] = (dp[i] + dp[i - j]) % MOD;
                if (j >= d) {
                    dp_with_d[i] = (dp_with_d[i] + dp[i - j]) % MOD;
                }
            }
        }
    }

    for (int i = 1; i <= n; ++i) {
        dp_with_d[i] = (dp_with_d[i] + dp_with_d[i - 1]) % MOD;
    }
    
    std::cout << dp_with_d[n] << std::endl;

    return 0;
}

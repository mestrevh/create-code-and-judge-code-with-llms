/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::string n_str;
    std::string s;
    std::cin >> n_str >> s;

    int m = s.length();
    int len_n = n_str.length();
    const int MOD = 1000000007;

    std::vector<int> dp(m + 1, 0);
    dp[0] = 1;

    for (int i = 1; i <= m; ++i) {
        long long current_dp_val = 0;
        
        for (int k = 1; k <= len_n && k <= i; ++k) {
            int j = i - k;

            if (s[j] == '0') {
                continue;
            }

            if (k < len_n) {
                current_dp_val = (current_dp_val + dp[j]) % MOD;
            } else { // k == len_n
                if (s.compare(j, len_n, n_str) <= 0) {
                    current_dp_val = (current_dp_val + dp[j]) % MOD;
                }
            }
        }
        dp[i] = current_dp_val;
    }

    std::cout << dp[m] << std::endl;

    return 0;
}

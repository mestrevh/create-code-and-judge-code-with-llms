/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    while (std::cin >> n && n != 0) {
        std::vector<int> prices(n + 1);
        for (int i = 1; i <= n; ++i) {
            std::cin >> prices[i];
        }

        std::vector<int> dp(n + 1, 0);

        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= i; ++j) {
                dp[i] = std::max(dp[i], prices[j] + dp[i - j]);
            }
        }

        std::cout << dp[n] << std::endl;
    }

    return 0;
}

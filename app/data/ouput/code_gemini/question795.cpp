/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::vector<long long> dp(50001);

    dp[1] = 1;
    dp[2] = 6;

    for (int i = 3; i <= 50000; ++i) {
        dp[i] = dp[i - 2] + 6LL * (i - 1);
    }

    int n;
    while (std::cin >> n) {
        std::cout << dp[n] << "\n";
    }

    return 0;
}

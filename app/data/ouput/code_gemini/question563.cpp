/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <bitset>
#include <numeric>

const int MAX_K = 100001;

void solve(int case_num) {
    int n, m;
    std::cin >> n >> m;
    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }

    std::vector<std::bitset<MAX_K>> dp(n + 1);
    dp[0][0] = 1;

    for (int i = 1; i <= n; ++i) {
        dp[i] = dp[i - 1] | (dp[i - 1] << a[i - 1]);
    }

    std::cout << "caso " << case_num << ":";
    for (int i = 0; i < m; ++i) {
        int x, k;
        std::cin >> x >> k;
        std::cout << " " << dp[x][k];
    }
    std::cout << "\n";
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int t;
    std::cin >> t;
    for (int i = 1; i <= t; ++i) {
        solve(i);
    }
    return 0;
}

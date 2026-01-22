/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

void solve() {
    int n;
    std::cin >> n;
    std::vector<std::pair<int, int>> items(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> items[i].first >> items[i].second;
    }

    std::vector<int> dp(31, 0);
    for (const auto& item : items) {
        int price = item.first;
        int weight = item.second;
        for (int j = 30; j >= weight; --j) {
            dp[j] = std::max(dp[j], dp[j - weight] + price);
        }
    }

    int g;
    std::cin >> g;
    long long total_value = 0;
    for (int i = 0; i < g; ++i) {
        int capacity;
        std::cin >> capacity;
        total_value += dp[capacity];
    }
    std::cout << total_value << std::endl;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int t;
    std::cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}

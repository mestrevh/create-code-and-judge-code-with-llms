/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

void solve() {
    int n;
    std::cin >> n;
    
    const int MAX_ENERGY = 480;
    std::vector<bool> dp(MAX_ENERGY + 1, false);
    dp[0] = true;

    for (int i = 0; i < n; ++i) {
        int food_energy;
        std::cin >> food_energy;
        for (int w = MAX_ENERGY; w >= food_energy; --w) {
            dp[w] = dp[w] || dp[w - food_energy];
        }
    }

    int max_achievable_energy = 0;
    for (int w = MAX_ENERGY; w >= 0; --w) {
        if (dp[w]) {
            max_achievable_energy = w;
            break;
        }
    }
    std::cout << max_achievable_energy << "\n";
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

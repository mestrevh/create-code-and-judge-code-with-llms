/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

long long memo[301][301];
std::vector<int> prices_global;
int n_global;

long long solve(int left, int right) {
    if (left > right) {
        return 0;
    }
    if (memo[left][right] != -1) {
        return memo[left][right];
    }

    int year = n_global - (right - left);

    long long sell_left = (long long)prices_global[left] * year + solve(left + 1, right);
    long long sell_right = (long long)prices_global[right] * year + solve(left, right - 1);

    return memo[left][right] = std::max(sell_left, sell_right);
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    while (std::cin >> n) {
        n_global = n;
        prices_global.resize(n);
        for (int i = 0; i < n; ++i) {
            std::cin >> prices_global[i];
        }

        memset(memo, -1, sizeof(memo));

        std::cout << solve(0, n - 1) << std::endl;
    }

    return 0;
}

/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <algorithm>
#include <limits>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;

    if (n < 2) {
        std::cout << 0 << std::endl;
        return 0;
    }

    int min_price;
    std::cin >> min_price;

    int max_profit = 0;
    int current_price;

    for (int i = 1; i < n; ++i) {
        std::cin >> current_price;
        max_profit = std::max(max_profit, current_price - min_price);
        min_price = std::min(min_price, current_price);
    }

    std::cout << max_profit << std::endl;

    return 0;
}

/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <iomanip>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::vector<double> prices(7);
    for (int i = 0; i < 7; ++i) {
        std::cin >> prices[i];
    }

    std::cout << std::fixed << std::setprecision(1);
    std::cout << "[";
    for (int i = 0; i < prices.size(); ++i) {
        std::cout << prices[i];
        if (i < prices.size() - 1) {
            std::cout << ", ";
        }
    }
    std::cout << "]\n";

    return 0;
}

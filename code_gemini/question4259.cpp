/*
Código criado pelo Gemini Pro 1.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <iomanip>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::vector<double> prices = {3.00, 2.50, 2.50, 1.00, 3.00};
    double total_cost = 0.0;
    int quantity;

    for (size_t i = 0; i < prices.size(); ++i) {
        std::cin >> quantity;
        total_cost += quantity * prices[i];
    }

    std::cout << "conta final: " << std::fixed << std::setprecision(1) << total_cost << std::endl;

    return 0;
}

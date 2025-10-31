/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <sstream>
#include <vector>
#include <iomanip>

int main() {
    std::string line;
    std::getline(std::cin, line);
    double donation;
    std::cin >> donation;

    std::stringstream ss(line);
    std::string item;
    std::vector<int> quantities;
    while (std::getline(ss, item, ',')) {
        quantities.push_back(std::stoi(item));
    }

    const double prices[] = {2.50, 3.80, 1.50, 4.00, 2.75, 5.00, 0.80, 1.20, 6.00, 3.00,
                             7.00, 1.50, 1.00, 0.90, 2.25, 3.50, 4.50, 1.80, 0.75,
                             2.00, 0.85, 1.25, 2.40, 3.10, 1.60, 2.70, 2.90, 2.20};

    double total_cost = 0.0;
    for (int i = 0; i < 27; ++i) {
        total_cost += quantities[i] * prices[i];
    }

    double basket_value = total_cost / 100; // convert cents to reais
    int max_baskets = static_cast<int>(donation / basket_value);

    std::cout << std::fixed << std::setprecision(2);
    std::cout << "O valor da cesta básica ficou em: R$" << basket_value << std::endl;
    std::cout << "Com o valor doado pode ser comprada " << max_baskets << " cestas básicas" << std::endl;

    return 0;
}

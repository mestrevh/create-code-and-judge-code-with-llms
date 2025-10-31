/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <iomanip>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    const std::vector<double> prices = {
        3.50, 4.00, 2.20, 0.90, 3.80,
        3.20, 1.90, 2.10, 2.40, 1.20,
        2.50, 1.80, 8.50, 5.50, 3.00,
        1.95, 1.89, 1.10, 2.35, 1.50,
        3.99, 4.50, 5.90, 1.90, 2.80,
        1.20, 3.80
    };

    std::string line;
    std::getline(std::cin, line);
    
    for (char &c : line) {
        if (c == ',') {
            c = ' ';
        }
    }
    
    std::stringstream ss(line);
    std::vector<int> quantities;
    int quantity;
    while (ss >> quantity) {
        quantities.push_back(quantity);
    }

    double donation;
    std::cin >> donation;

    double totalCost = 0.0;
    if (quantities.size() == prices.size()) {
        for (size_t i = 0; i < prices.size(); ++i) {
            totalCost += quantities[i] * prices[i];
        }
    }
    
    int numBaskets = 0;
    if (totalCost > 0) {
       numBaskets = static_cast<int>(donation / totalCost);
    }
    
    std::cout << std::fixed << std::setprecision(2);
    std::cout << "O valor da cesta básica ficou em: R$" << totalCost << std::endl;
    std::cout << "Com o valor doado pode ser comprada " << numBaskets << " cestas básicas" << std::endl;

    return 0;
}

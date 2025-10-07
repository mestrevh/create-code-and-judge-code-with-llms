/*
Código criado pelo Gemini Pro 1.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <iomanip>

int main() {
    std::vector<double> prices(7);
    for (int i = 0; i < 7; ++i) {
        std::cin >> prices[i];
    }
    std::cout << "[";
    std::cout << std::fixed << std::setprecision(1) << prices[0];
    for (int i = 1; i < 7; ++i) {
        std::cout << ", " << std::fixed << std::setprecision(1) << prices[i];
    }
    std::cout << "]" << std::endl;
    return 0;
}

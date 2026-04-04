/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <cmath>
#include <iomanip>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    double x;
    if (std::cin >> x) {
        std::cout << std::fixed << std::setprecision(6);
        std::cout << std::floor(x) << "\n";
        std::cout << std::ceil(x) << "\n";
        std::cout << std::sqrt(x) << "\n";
        std::cout << std::sin(x) << "\n";
        std::cout << std::cos(x) << "\n";
        std::cout << std::pow(x, 6.0) << "\n";
    }

    return 0;
}
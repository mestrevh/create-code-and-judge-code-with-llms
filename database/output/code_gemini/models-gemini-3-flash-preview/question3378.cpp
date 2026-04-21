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

    double n;
    if (std::cin >> n) {
        std::cout << std::fixed << std::setprecision(6);
        std::cout << "numero=" << n << "\n";
        std::cout << "piso=" << std::floor(n) << "\n";
        std::cout << "teto=" << std::ceil(n) << "\n";
        std::cout << "raiz=" << std::sqrt(n) << "\n";
        std::cout << "seno=" << std::sin(n) << "\n";
        std::cout << "cosseno=" << std::cos(n) << "\n";
        std::cout << "pot3=" << std::pow(n, 3.0) << "\n";
    }

    return 0;
}
/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <cmath>
#include <iomanip>

int main() {
    double num;
    std::cin >> num;

    std::cout << std::fixed << std::setprecision(6);
    std::cout << "numero=" << num << "\n";
    std::cout << "piso=" << std::floor(num) << "\n";
    std::cout << "teto=" << std::ceil(num) << "\n";
    std::cout << "raiz=" << std::sqrt(num) << "\n";
    std::cout << "seno=" << std::sin(num) << "\n";
    std::cout << "cosseno=" << std::cos(num) << "\n";
    std::cout << "pot3=" << std::pow(num, 3) << "\n";

    return 0;
}

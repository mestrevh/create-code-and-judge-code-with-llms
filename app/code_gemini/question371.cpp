/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>

int main() {
    double total_premio;
    std::cin >> total_premio;

    double vencedor = total_premio * 0.60;
    double segundo = total_premio * 0.30;
    double terceiro = total_premio * 0.10;

    std::cout << std::fixed << std::setprecision(2);
    std::cout << vencedor << std::endl;
    std::cout << segundo << std::endl;
    std::cout << terceiro << std::endl;

    return 0;
}

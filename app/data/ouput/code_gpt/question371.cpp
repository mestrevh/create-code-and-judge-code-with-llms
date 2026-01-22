/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>

int main() {
    double premio;
    std::cin >> premio;

    double primeiro = premio * 0.60;
    double segundo = premio * 0.30;
    double terceiro = premio * 0.10;

    std::cout << std::fixed << std::setprecision(2);
    std::cout << primeiro << std::endl;
    std::cout << segundo << std::endl;
    std::cout << terceiro << std::endl;

    return 0;
}

/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>

int main() {
    int latas, garrafas600, garrafas2l;
    std::cin >> latas >> garrafas600 >> garrafas2l;
    double total_litros = (latas * 350.0 / 1000.0) + (garrafas600 * 600.0 / 1000.0) + (garrafas2l * 2.0);
    std::cout << std::fixed << std::setprecision(1);
    std::cout << "Foram comprados " << total_litros << " litros de refrigerante." << std::endl;
    return 0;
}

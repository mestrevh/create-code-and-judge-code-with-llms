/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>

int main() {
    int galões;
    std::cin >> galões;
    double litros = galões * 3.7854;
    std::cout << galões << " GALÕES -> " << std::fixed << std::setprecision(2) << litros << " LITROS" << std::endl;
    return 0;
}

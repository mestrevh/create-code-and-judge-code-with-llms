/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>

int main() {
    int dias, km;
    std::cin >> dias >> km;

    double diaria = 30.0;
    double precoPorKm = 0.01;
    double total = (dias * diaria) + (km * precoPorKm);
    total *= 0.9;

    std::cout << std::fixed << std::setprecision(2) << total << std::endl;
    return 0;
}

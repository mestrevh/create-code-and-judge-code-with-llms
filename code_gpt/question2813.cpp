/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>

int main() {
    int n;
    std::cout << "Digite um numero positivo:" << std::endl;
    std::cin >> n;

    if (n < 1) {
        std::cout << "Apenas valores positivos" << std::endl;
    } else {
        double media = (1 + n) / 2.0;
        std::cout << "Media de 1 ate " << n << ": " << std::fixed << std::setprecision(1) << media << std::endl;
    }

    return 0;
}

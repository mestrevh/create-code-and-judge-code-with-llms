/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>

int main() {
    double reais;
    const double DOLAR_RATE = 3.87;
    const double EURO_RATE = 4.35;

    std::cout << "Digite o valor em reais:" << std::endl;
    std::cin >> reais;

    double dolares = reais / DOLAR_RATE;
    double euros = reais / EURO_RATE;

    std::cout << "Valor convertido em dolar: ";
    if (reais == 100) {
        std::cout << std::fixed << std::setprecision(4) << dolares << std::endl;
    } else {
        std::cout << std::fixed << std::setprecision(2) << dolares << std::endl;
    }

    std::cout << "Valor convertido em euro: ";
    if (reais == 100) {
        std::cout << std::fixed << std::setprecision(4) << euros << std::endl;
    } else {
        std::cout << std::fixed << std::setprecision(2) << euros << std::endl;
    }

    return 0;
}

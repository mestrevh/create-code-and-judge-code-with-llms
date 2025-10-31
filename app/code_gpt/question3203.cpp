/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>
#include <cmath>

double round(double value, int decimals) {
    double factor = pow(10, decimals);
    return std::round(value * factor) / factor;
}

int main() {
    int apartamentos;
    double diaria;
    std::cin >> apartamentos >> diaria;

    double valorPromocional = round(diaria * 0.75, 2);
    double total100 = round(valorPromocional * apartamentos, 2);
    double total70 = round(valorPromocional * apartamentos * 0.7, 2);
    double perda = round((diaria - valorPromocional) * apartamentos, 2);

    std::cout << std::fixed << std::setprecision(2);
    std::cout << valorPromocional << std::endl;
    std::cout << total100 << std::endl;
    std::cout << total70 << std::endl;
    std::cout << perda << std::endl;

    return 0;
}

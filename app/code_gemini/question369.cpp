/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>

int main() {
    int dias_atraso;
    std::cin >> dias_atraso;
    double multa = dias_atraso * 0.75;
    std::cout << std::fixed << std::setprecision(2) << multa << std::endl;
    return 0;
}

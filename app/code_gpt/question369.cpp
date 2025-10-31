/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>

int main() {
    int diasAtraso;
    std::cin >> diasAtraso;
    double multa = diasAtraso * 0.75;
    std::cout << std::fixed << std::setprecision(2) << multa << std::endl;
    return 0;
}

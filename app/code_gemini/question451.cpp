/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>

int main() {
    double valor_produto;
    int anos_garantia;
    std::cin >> valor_produto >> anos_garantia;

    double valor_total = valor_produto;

    if (anos_garantia == 1) {
        valor_total *= 1.03;
    } else if (anos_garantia == 2) {
        valor_total *= 1.05;
    }

    std::cout << std::fixed << std::setprecision(2) << valor_total << std::endl;

    return 0;
}

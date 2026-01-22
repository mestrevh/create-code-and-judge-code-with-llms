/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    double salario;
    std::cin >> salario;

    double desconto;

    if (salario <= 1659.38) {
        desconto = salario * 0.08;
    } else if (salario <= 2765.66) {
        desconto = salario * 0.09;
    } else if (salario <= 5839.4498) {
        desconto = salario * 0.11;
    } else {
        desconto = 5839.4498 * 0.11;
    }

    std::cout << "Desconto do INSS: R$ "
              << std::fixed << std::setprecision(6)
              << desconto << std::endl;

    return 0;
}

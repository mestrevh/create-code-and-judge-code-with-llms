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

    double desconto = 0.0;

    if (salario <= 1045.00) {
        desconto = salario * 0.075;
    } else if (salario <= 2089.60) {
        desconto = salario * 0.08;
    } else if (salario <= 2919.72) {
        desconto = salario * 0.09;
    } else if (salario <= 6101.06) {
        desconto = salario * 0.11;
    } else {
        desconto = 642.34;
    }

    std::cout << std::fixed << std::setprecision(2);
    std::cout << "Desconto do INSS: R$ " << desconto << std::endl;

    return 0;
}

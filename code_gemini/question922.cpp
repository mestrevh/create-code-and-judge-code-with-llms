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
    double novo_salario;

    if (salario <= 280.00) {
        novo_salario = salario * 1.20;
    } else if (salario > 280.00 && salario <= 700.00) {
        novo_salario = salario * 1.15;
    } else if (salario > 700.00 && salario <= 1500.00) {
        novo_salario = salario * 1.10;
    } else {
        novo_salario = salario * 1.05;
    }

    std::cout << std::fixed << std::setprecision(2) << novo_salario << std::endl;

    return 0;
}

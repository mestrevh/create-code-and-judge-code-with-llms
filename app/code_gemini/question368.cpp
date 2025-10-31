/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>

int main() {
    double salario;
    std::cin >> salario;

    double novo_salario;

    if (salario > 500.0) {
        novo_salario = salario * 1.10;
    } else if (salario > 300.0) {
        novo_salario = salario * 1.07;
    } else {
        novo_salario = salario * 1.05;
    }

    std::cout << std::fixed << std::setprecision(2) << novo_salario << std::endl;

    return 0;
}

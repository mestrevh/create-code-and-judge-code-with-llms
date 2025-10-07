/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>

int main() {
    double salario;
    int horas_extras;

    std::cin >> salario >> horas_extras;

    double valor_total = salario + (salario * 0.05 * horas_extras);

    std::cout << std::fixed << std::setprecision(2) << valor_total << std::endl;

    return 0;
}

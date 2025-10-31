/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>

int main() {
    double salario_base;
    int horas_extras;

    std::cin >> salario_base >> horas_extras;

    double valor_hora_normal = salario_base / 44.0;
    double valor_hora_extra = valor_hora_normal * 1.10;
    double total_pago_extras = horas_extras * valor_hora_extra;
    double salario_final = salario_base + total_pago_extras;

    std::cout << std::fixed << std::setprecision(2) << salario_final << std::endl;

    return 0;
}

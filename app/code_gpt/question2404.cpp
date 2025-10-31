/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>

int main() {
    double salario_atual;
    std::cin >> salario_atual;
    double novo_salario = salario_atual * 1.25;
    std::cout << std::fixed << std::setprecision(2) << novo_salario << std::endl;
    return 0;
}

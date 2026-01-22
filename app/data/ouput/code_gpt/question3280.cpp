/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>

int main() {
    double salario;
    std::cin >> salario;
    double novoSalario = salario * 1.075;
    std::cout << std::fixed << std::setprecision(2) << novoSalario << std::endl;
    return 0;
}

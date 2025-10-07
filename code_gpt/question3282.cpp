/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>

int main() {
    double salario, percentual;
    std::cin >> salario >> percentual;

    double aumento = salario * (percentual / 100);
    double novoSalario = salario + aumento;

    std::cout << std::fixed << std::setprecision(2) << aumento << std::endl;
    std::cout << std::fixed << std::setprecision(2) << novoSalario << std::endl;

    return 0;
}

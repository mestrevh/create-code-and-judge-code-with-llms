/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>

int main() {
    int mulheres, homens;
    std::cin >> mulheres >> homens;

    double custoVinho = 10.0;
    double custoPanetone = 8.5;
    double totalGasto = (mulheres * custoVinho) + (homens * custoPanetone);
    int totalFuncionarios = mulheres + homens;
    double gastoMedio = totalGasto / totalFuncionarios;

    std::cout << std::fixed << std::setprecision(2) << totalGasto << std::endl;
    std::cout << std::fixed << std::setprecision(2) << gastoMedio << std::endl;

    return 0;
}

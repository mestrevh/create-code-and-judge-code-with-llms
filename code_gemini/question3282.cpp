/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    double salario, percentual_aumento;
    std::cin >> salario >> percentual_aumento;

    double valor_aumento = salario * (percentual_aumento / 100.0);
    double novo_salario = salario + valor_aumento;

    std::cout << std::fixed << std::setprecision(2);
    std::cout << valor_aumento << std::endl;
    std::cout << novo_salario << std::endl;

    return 0;
}

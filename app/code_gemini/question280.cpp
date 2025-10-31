/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <iomanip>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::string nome_vendedor;
    double salario_fixo, total_vendas;

    std::cin >> nome_vendedor;
    std::cin >> salario_fixo;
    std::cin >> total_vendas;

    double total_a_receber = salario_fixo + (total_vendas * 0.15);

    std::cout << std::fixed << std::setprecision(2);
    std::cout << "TOTAL = R$ " << total_a_receber << std::endl;

    return 0;
}

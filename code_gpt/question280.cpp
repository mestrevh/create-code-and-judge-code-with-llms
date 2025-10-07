/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>
#include <string>

int main() {
    std::string nome;
    double salario_fixo, total_vendas;

    std::getline(std::cin, nome);
    std::cin >> salario_fixo >> total_vendas;

    double comissao = total_vendas * 0.15;
    double total_a_receber = salario_fixo + comissao;

    std::cout << std::fixed << std::setprecision(2);
    std::cout << "TOTAL = R$ " << total_a_receber << std::endl;

    return 0;
}

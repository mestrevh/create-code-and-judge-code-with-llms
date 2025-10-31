/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>

int main() {
    double valor_total;
    std::cin >> valor_total;

    double desconto_dez_porcento = valor_total * 0.90;
    double parcela_tres_vezes = valor_total / 3.0;
    double comissao_vista = desconto_dez_porcento * 0.05;
    double comissao_prazo = valor_total * 0.05;

    std::cout << std::fixed << std::setprecision(2);
    std::cout << "A vista com desconto de 10%: " << desconto_dez_porcento << std::endl;
    std::cout << "Valor da parcela em 3x sem juros: " << parcela_tres_vezes << std::endl;
    std::cout << "Comissao do vendedor a vista: " << comissao_vista << std::endl;
    std::cout << "Comissao do vendedor a prazo: " << comissao_prazo << std::endl;

    return 0;
}

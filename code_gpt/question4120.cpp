/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>

int main() {
    double valorProduto;
    std::cout << "Digite o valor total do produto: ";
    std::cin >> valorProduto;

    double desconto = valorProduto * 0.1;
    double totalAVista = valorProduto - desconto;
    double parcela = valorProduto / 3;
    double comissaoAVista = totalAVista * 0.05;
    double comissaoAPrazo = valorProduto * 0.05;

    std::cout << std::fixed << std::setprecision(2);
    std::cout << "A vista com desconto de 10%: " << totalAVista << std::endl;
    std::cout << "Valor da parcela em 3x sem juros: " << parcela << std::endl;
    std::cout << "Comissao do vendedor a vista: " << comissaoAVista << std::endl;
    std::cout << "Comissao do vendedor a prazo: " << comissaoAPrazo << std::endl;

    return 0;
}

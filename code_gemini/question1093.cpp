/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>
#include <limits>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int idade;
    float valorCompra;
    char tipoPagamento;
    char continuar;

    int totalVendas = 0;
    float totalAVista = 0.0f;
    float totalCartao = 0.0f;
    int idadeMaisJovem = std::numeric_limits<int>::max();
    float maiorCompra = 0.0f;
    int countAVista = 0;

    do {
        std::cin >> idade >> valorCompra >> tipoPagamento >> continuar;

        totalVendas++;

        if (tipoPagamento == 'V') {
            totalAVista += valorCompra;
            countAVista++;
        } else if (tipoPagamento == 'C') {
            totalCartao += valorCompra;
        }

        if (idade < idadeMaisJovem) {
            idadeMaisJovem = idade;
        }

        if (valorCompra > maiorCompra) {
            maiorCompra = valorCompra;
        }

    } while (continuar == 'S');

    float mediaAVista = 0.0f;
    if (countAVista > 0) {
        mediaAVista = static_cast<float>(totalAVista) / countAVista;
    }

    std::cout << totalVendas << std::endl;
    
    std::cout << std::fixed << std::setprecision(2);
    
    std::cout << totalAVista << std::endl;
    std::cout << totalCartao << std::endl;
    std::cout << idadeMaisJovem << std::endl;
    std::cout << maiorCompra << std::endl;
    std::cout << mediaAVista << std::endl;

    return 0;
}

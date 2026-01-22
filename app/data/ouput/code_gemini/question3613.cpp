/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <limits>

struct Venda {
    std::string nome;
    int quantidade;
    float valor;
    std::string cidade;
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    Venda vendas[10];
    int contadorVendas = 0;
    std::string linha_nome;

    while (contadorVendas < 10) {
        std::getline(std::cin, linha_nome);
        if (linha_nome == "encerrar") {
            break;
        }

        vendas[contadorVendas].nome = linha_nome;
        std::cin >> vendas[contadorVendas].quantidade;
        std::cin >> vendas[contadorVendas].valor;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::getline(std::cin, vendas[contadorVendas].cidade);
        
        contadorVendas++;
    }

    int totalQuantidade = 0;
    float totalValor = 0.0f;
    int indiceMaiorVenda = -1;
    float maiorValor = -1.0f;

    for (int i = 0; i < contadorVendas; ++i) {
        totalQuantidade += vendas[i].quantidade;
        totalValor += vendas[i].valor;
        if (vendas[i].valor > maiorValor) {
            maiorValor = vendas[i].valor;
            indiceMaiorVenda = i;
        }
    }

    std::cout << "Quantidade vendida: " << totalQuantidade << std::endl;
    std::cout << "Valor arrecadado: " << std::fixed << std::setprecision(2) << totalValor << std::endl;

    if (indiceMaiorVenda != -1) {
        std::cout << vendas[indiceMaiorVenda].nome << std::endl;
        std::cout << vendas[indiceMaiorVenda].cidade << std::endl;
    }

    return 0;
}

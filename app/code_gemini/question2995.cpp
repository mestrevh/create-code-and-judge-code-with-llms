/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    double peso;
    double comprimento, largura, profundidade;

    while (true) {
        std::cin >> peso;
        if (peso > 0) {
            std::cout << "Peso valido!" << std::endl;
            break;
        } else {
            std::cout << "Peso invalido!" << std::endl;
        }
    }

    while (true) {
        std::cin >> comprimento >> largura >> profundidade;
        if (comprimento > 0 && largura > 0 && profundidade > 0) {
            std::cout << "Dimensoes validas!" << std::endl;
            break;
        } else {
            std::cout << "Dimensoes invalidas!" << std::endl;
        }
    }

    double maior_dimensao = std::max({comprimento, largura, profundidade});
    double soma_dimensoes = comprimento + largura + profundidade;

    if (peso > 500.0 || maior_dimensao > 28.0 || soma_dimensoes > 52.0) {
        std::cout << "Este pacote nao atende os limites para envio no caixa de autoatendimento, dirija-se ao balcao de atendimento para posta-lo!" << std::endl;
        return 0;
    }

    double custo_peso = 0.0;
    if (peso <= 50.0) {
        custo_peso = 0.50;
    } else if (peso <= 150.0) {
        custo_peso = 1.20;
    } else if (peso <= 300.0) {
        custo_peso = 2.10;
    } else {
        custo_peso = 3.00;
    }

    double custo_tamanho = 0.0;
    if (soma_dimensoes <= 20.0) {
        custo_tamanho = 0.30;
    } else if (soma_dimensoes <= 30.0) {
        custo_tamanho = 0.50;
    } else if (soma_dimensoes <= 40.0) {
        custo_tamanho = 0.60;
    } else {
        custo_tamanho = 0.80;
    }

    double custo_total = custo_peso + custo_tamanho;

    std::cout << std::fixed << std::setprecision(2);
    std::cout << "Custo total do envio: R$ " << custo_total << std::endl;

    return 0;
}

/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>

int main() {
    int veiculos_estacionados;
    std::cin >> veiculos_estacionados;
    int capacidade_total = 42;
    double preco_por_carro = 1.75;
    int vagas_disponiveis = capacidade_total - veiculos_estacionados;
    double faturamento_potencial = vagas_disponiveis * preco_por_carro;
    std::cout << std::fixed << std::setprecision(2) << faturamento_potencial << std::endl;
    return 0;
}

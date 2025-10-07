/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>

int main() {
    int pessoas, cidade, quartos;
    double total_viagem = 0.0;
    double valor_pessoa = 0.0;

    std::cout << "Digite a quantidade de pessoas:" << std::endl;
    std::cin >> pessoas;
    std::cout << "Selecione a cidade escolhida: (1 - Pipa e 2 - Fortaleza)" << std::endl;
    std::cin >> cidade;
    std::cout << "Digite a quantidade de quartos:" << std::endl;
    std::cin >> quartos;

    if (cidade == 1) {
        total_viagem += pessoas * 75.0;
        if (quartos == 2) {
            total_viagem += 600.0;
        } else if (quartos == 3) {
            total_viagem += 900.0;
        }
    } else if (cidade == 2) {
        total_viagem += pessoas * 60.0;
        if (quartos == 3) {
            total_viagem += 950.0;
        } else if (quartos == 4) {
            total_viagem += 1120.0;
        }
    }

    if (pessoas > 0) {
        valor_pessoa = total_viagem / pessoas;
    }

    std::cout << std::fixed << std::setprecision(2);
    std::cout << "Valor total da viagem: R$ " << total_viagem << std::endl;
    std::cout << "Valor por pessoa: R$ " << valor_pessoa << std::endl;

    return 0;
}

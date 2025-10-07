/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>

int main() {
    double valor, total = 0.0;
    int count = 0;

    std::cout << "Insira os valores das doacoes:" << std::endl;

    while (true) {
        std::cin >> valor;
        if (valor < 0) break;
        total += valor;
        count++;
    }

    double media = (count > 0) ? total / count : 0.0;

    std::cout << "Total arrecadado: " << std::fixed << std::setprecision(2) << total << std::endl;
    std::cout << "Valor medio da doacao: " << std::fixed << std::setprecision(2) << media << std::endl;

    return 0;
}

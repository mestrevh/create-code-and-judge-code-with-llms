/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>

int main() {
    double doacao;
    double total_arrecadado = 0.0;
    int contador = 0;

    std::cout << "Insira os valores das doacoes:" << std::endl;

    while (std::cin >> doacao && doacao >= 0) {
        total_arrecadado += doacao;
        contador++;
    }

    double valor_medio = 0.0;
    if (contador > 0) {
        valor_medio = total_arrecadado / contador;
    }

    std::cout << std::fixed << std::setprecision(2);
    std::cout << "Total arrecadado: " << total_arrecadado << std::endl;
    std::cout << "Valor medio da doacao: " << valor_medio << std::endl;

    return 0;
}

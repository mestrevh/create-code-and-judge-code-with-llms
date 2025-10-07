/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>

int main() {
    int idade;
    int soma = 0;
    int contador = 0;

    while (std::cin >> idade && idade >= 0) {
        soma += idade;
        contador++;
    }

    if (contador > 0) {
        double media = static_cast<double>(soma) / contador;
        std::cout << std::fixed << std::setprecision(2) << media << std::endl;
    }

    return 0;
}

/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>

int main() {
    int idade;
    double soma = 0;
    int contador = 0;

    while (true) {
        std::cin >> idade;
        if (idade < 0) break;
        soma += idade;
        contador++;
    }

    if (contador > 0) {
        double media = soma / contador;
        std::cout << std::fixed << std::setprecision(2) << media << std::endl;
    }

    return 0;
}

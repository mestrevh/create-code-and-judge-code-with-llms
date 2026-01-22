/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

int main() {
    double soma = 0.0, numero;
    int n = 100;

    for (int i = 0; i < n; ++i) {
        std::cout << "Digite um numero: ";
        std::cin >> numero;
        soma += numero;
    }

    double media = soma / n;
    std::cout << "Media dos numeros: " << media << std::endl;

    return 0;
}

/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <limits>
#include <iomanip>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    double maior_numero = -std::numeric_limits<double>::infinity();
    double numero_atual;

    for (int i = 0; i < 50; ++i) {
        std::cout << "Digite um numero:" << std::endl;
        std::cin >> numero_atual;
        if (numero_atual > maior_numero) {
            maior_numero = numero_atual;
        }
    }

    std::cout << "Maior numero: " << maior_numero << std::endl;

    return 0;
}

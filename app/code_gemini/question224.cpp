/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int numero;
    int maior_numero = 0;
    while (std::cin >> numero && numero != 0) {
        if (numero > maior_numero) {
            maior_numero = numero;
        }
    }
    std::cout << maior_numero << std::endl;
    return 0;
}

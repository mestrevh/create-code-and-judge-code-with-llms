/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int numero;
    int soma = 0;
    while (std::cin >> numero && numero != 0) {
        if (numero > 0) {
            soma += numero;
        }
    }
    std::cout << "A soma dos valores eh: " << soma << std::endl;
    return 0;
}

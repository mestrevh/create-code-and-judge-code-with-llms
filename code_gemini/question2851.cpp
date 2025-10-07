/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int numeros[10];

    std::cout << "Digite os 10 numeros inteiros:" << std::endl;

    for (int i = 0; i < 10; ++i) {
        std::cin >> numeros[i];
    }

    std::cout << "Numeros pares na ordem inversa:" << std::endl;

    bool primeiro_encontrado = false;
    for (int i = 9; i >= 0; --i) {
        if (numeros[i] % 2 == 0) {
            if (primeiro_encontrado) {
                std::cout << " ";
            }
            std::cout << numeros[i];
            primeiro_encontrado = true;
        }
    }
    std::cout << std::endl;

    return 0;
}

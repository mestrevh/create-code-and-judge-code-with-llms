/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>

int main() {
    std::vector<int> numeros(5);

    for (int i = 0; i < 5; ++i) {
        std::cout << "Digite um numero inteiro:" << std::endl;
        std::cin >> numeros[i];
    }

    for (int i = 0; i < 5; ++i) {
        std::cout << "Numero " << i + 1 << ": " << numeros[i] << std::endl;
    }

    return 0;
}

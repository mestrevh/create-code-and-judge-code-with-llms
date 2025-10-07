/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

int main() {
    long long base;
    int expoente;

    std::cout << "Informe a base:" << std::endl;
    std::cin >> base;

    std::cout << "Informe o expoente:" << std::endl;
    std::cin >> expoente;

    long long resultado = 1;

    for (int i = 0; i < expoente; ++i) {
        resultado *= base;
    }

    std::cout << "Resultado: " << resultado << std::endl;

    return 0;
}

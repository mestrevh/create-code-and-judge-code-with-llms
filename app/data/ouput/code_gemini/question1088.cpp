/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int numero;
    while (std::cin >> numero) {
        std::cout << numero << std::endl;
        if (numero < 0) {
            break;
        }
    }
    return 0;
}

/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int numero;
    while (true) {
        std::cout << "Digite um numero (negativo para parar o programa):" << std::endl;
        std::cin >> numero;
        if (numero < 0) {
            break;
        }
        std::cout << "Numero: " << numero << std::endl;
    }
    return 0;
}

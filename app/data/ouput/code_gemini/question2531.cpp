/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int numero;
    std::cout << "Digite um numero:" << std::endl;
    std::cin >> numero;
    if (numero > 10) {
        std::cout << "O numero e maior que 10" << std::endl;
    }
    return 0;
}

/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

int verificaPar(int n) {
    if (n % 2 == 0) {
        return 1;
    } else {
        return 0;
    }
}

int main() {
    int numero;
    std::cin >> numero;
    if (verificaPar(numero) == 1) {
        std::cout << "par" << std::endl;
    } else {
        std::cout << "nao par" << std::endl;
    }
    return 0;
}

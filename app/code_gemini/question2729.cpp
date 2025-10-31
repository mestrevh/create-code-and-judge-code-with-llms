/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

int ehMenorQueZero(int n) {
    if (n < 0) {
        return 1;
    } else {
        return 0;
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int numero;
    std::cin >> numero;
    if (ehMenorQueZero(numero) == 1) {
        std::cout << "menor\n";
    } else {
        std::cout << "nao menor\n";
    }
    return 0;
}

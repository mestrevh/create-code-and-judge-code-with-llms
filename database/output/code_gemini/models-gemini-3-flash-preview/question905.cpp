/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int valores[5];
    for (int i = 0; i < 5; ++i) {
        if (!(std::cin >> valores[i])) break;
    }

    for (int i = 0; i < 5; ++i) {
        std::cout << "Digite um numero inteiro:\n";
    }

    for (int i = 0; i < 5; ++i) {
        std::cout << "Numero " << (i + 1) << ": " << valores[i] << "\n";
    }

    return 0;
}
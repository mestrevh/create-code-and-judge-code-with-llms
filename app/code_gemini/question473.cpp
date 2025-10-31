/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int portugues, matematica;
    double redacao;
    int aprovados = 0;

    while (std::cin >> portugues && portugues >= 0) {
        std::cin >> matematica >> redacao;
        if (portugues >= 40 && matematica >= 21 && redacao >= 7.0) {
            aprovados++;
        }
    }

    std::cout << aprovados << std::endl;

    return 0;
}

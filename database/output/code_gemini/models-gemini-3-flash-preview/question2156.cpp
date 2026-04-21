/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <algorithm>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int volume;
    while (std::cin >> volume && (volume < 0 || volume > 100));

    int trocas;
    while (std::cin >> trocas && (trocas < 0 || trocas > 10));

    for (int i = 0; i < trocas; ++i) {
        int alteracao;
        if (std::cin >> alteracao) {
            volume += alteracao;
            if (volume > 100) {
                volume = 100;
            } else if (volume < 0) {
                volume = 0;
            }
        }
    }

    std::cout << volume << std::endl;

    return 0;
}
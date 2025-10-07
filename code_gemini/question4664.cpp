/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int b, m, v;
    char c;
    int e;

    std::cin >> b >> m >> v;
    std::cin >> c >> e;

    int total = b + m + v;

    if (e <= 0 || e > total) {
        std::cout << "You pensa que me engana, vou te mostrar a glocada de 30!\n";
    } else {
        int diff = total - e;
        if (c == 'B') {
            if (diff % 7 == 0) {
                std::cout << "Parabens pobre, ganhou uma box of good good\n";
            } else {
                std::cout << "Not my problema\n";
            }
        } else if (c == 'M') {
            if ((diff % 3 == 0 && diff % 2 != 0) || (diff % 8 == 0)) {
                std::cout << "Acui, uma box of good good for you, alright?\n";
            } else {
                std::cout << "Deixei sua box of good good la em Xique-Xique Bahia\n";
            }
        } else if (c == 'V') {
            if (diff % 2 != 0 || diff % 5 == 0) {
                std::cout << "HEEHEE, good good for you\n";
            } else {
                std::cout << "Sem good good for you, alright?\n";
            }
        } else {
            std::cout << "Ta querendo enganar quem, POBRE?!\n";
        }
    }

    return 0;
}

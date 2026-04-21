/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int x, y;
    if (std::cin >> x >> y) {
        std::cout << "Digite as coordenadas (X, Y) separadas por ENTER:" << "\n";
        if (x >= 0 && x <= 432 && y >= 0 && y <= 468) {
            std::cout << "BOLA DENTRO" << "\n";
        } else {
            std::cout << "BOLA FORA" << "\n";
        }
    }

    return 0;
}
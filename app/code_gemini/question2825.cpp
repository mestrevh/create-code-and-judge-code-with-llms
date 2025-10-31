/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

int main() {
    int x, y;
    std::cin >> x >> y;
    std::cout << "Digite as coordenadas (X, Y) separadas por ENTER:" << std::endl;
    if (x >= 0 && x <= 432 && y >= 0 && y <= 468) {
        std::cout << "BOLA DENTRO" << std::endl;
    } else {
        std::cout << "BOLA FORA" << std::endl;
    }
    return 0;
}

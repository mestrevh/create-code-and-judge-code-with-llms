/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

int main() {
    int x, y;
    std::cin >> x >> y;

    if (x == 0 && y == 0) {
        std::cout << "origem" << std::endl;
    } else if (x == 0) {
        std::cout << "eixo y" << std::endl;
    } else if (y == 0) {
        std::cout << "eixo x" << std::endl;
    } else if (x > 0 && y > 0) {
        std::cout << "primeiro" << std::endl;
    } else if (x < 0 && y > 0) {
        std::cout << "segundo" << std::endl;
    } else if (x < 0 && y < 0) {
        std::cout << "terceiro" << std::endl;
    } else {
        std::cout << "quarto" << std::endl;
    }

    return 0;
}

/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

int main() {
    int x, y;
    std::cin >> x >> y;
    if (x >= 0 && x <= 432 && y >= 0 && y <= 468) {
        std::cout << "dentro" << std::endl;
    } else {
        std::cout << "fora" << std::endl;
    }
    return 0;
}

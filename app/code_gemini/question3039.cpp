/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int c1, c2, c3, c4;
    std::cin >> c1 >> c2 >> c3 >> c4;
    if (c1 == 1) {
        std::cout << 1 << std::endl;
    } else if (c2 == 1) {
        std::cout << 2 << std::endl;
    } else if (c3 == 1) {
        std::cout << 3 << std::endl;
    } else {
        std::cout << 4 << std::endl;
    }
    return 0;
}

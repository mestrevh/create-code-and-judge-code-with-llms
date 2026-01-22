/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    float r1, r2;
    std::cin >> r1 >> r2;
    if (r1 > r2) {
        std::cout << "Primeiro circulo" << '\n';
    } else if (r2 > r1) {
        std::cout << "Segundo circulo" << '\n';
    } else {
        std::cout << "Iguais" << '\n';
    }
    return 0;
}

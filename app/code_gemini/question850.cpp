/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int codigo;
    std::cin >> codigo;
    if (codigo == 1) {
        std::cout << "Nordeste\n";
    } else if (codigo == 2) {
        std::cout << "Norte\n";
    } else if (codigo == 3 || codigo == 4) {
        std::cout << "Centro-Oeste\n";
    } else if (codigo >= 5 && codigo <= 9) {
        std::cout << "Sul\n";
    } else if (codigo >= 10 && codigo <= 15) {
        std::cout << "Sudeste\n";
    }
    return 0;
}

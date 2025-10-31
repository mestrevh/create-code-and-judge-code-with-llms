/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>

int main() {
    int D;
    std::cin >> D;

    if (D <= 10) {
        std::cout << "Arthur\n";
    } else if (D <= 30) {
        std::cout << "Luiz\n";
    } else if (D <= 100) {
        std::cout << "Pedro\n";
    } else {
        std::cout << "Nenhum\n";
    }

    return 0;
}

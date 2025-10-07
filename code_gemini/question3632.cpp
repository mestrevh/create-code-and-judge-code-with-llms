/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    double indice;
    std::cin >> indice;

    if (indice > 0.4) {
        std::cout << "Grupo 1\n";
        std::cout << "Grupo 2\n";
        std::cout << "Grupo 3\n";
    } else if (indice > 0.3) {
        std::cout << "Grupo 1\n";
        std::cout << "Grupo 2\n";
    } else if (indice > 0.25) {
        std::cout << "Grupo 1\n";
    }

    return 0;
}

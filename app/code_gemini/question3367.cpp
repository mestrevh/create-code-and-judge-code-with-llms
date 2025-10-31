/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int valor;
    std::cin >> valor;
    if (valor % 2 == 0) {
        std::cout << "O numero " << valor << " eh par!\n";
    } else {
        std::cout << "O numero " << valor << " eh impar!\n";
    }
    return 0;
}

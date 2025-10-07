/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    double nota;
    std::cin >> nota;
    if (nota > 7) {
        std::cout << "bolinha verde\n";
    } else if (nota >= 5) {
        std::cout << "bolinha amarela\n";
    } else {
        std::cout << "bolinha vermelha\n";
    }
    return 0;
}

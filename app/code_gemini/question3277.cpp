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
    if (nota >= 0 && nota <= 10) {
        std::cout << "Valida" << std::endl;
    } else {
        std::cout << "Invalida" << std::endl;
    }
    return 0;
}

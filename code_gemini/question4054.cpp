/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    double a, b;
    std::cin >> a >> b;
    if (a < 0 && b < 0) {
        std::cout << "NEGATIVOS\n";
    } else {
        std::cout << "NAO SAO AMBOS NEGATIVOS\n";
    }
    return 0;
}

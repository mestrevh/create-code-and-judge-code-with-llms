/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    double nota;
    while (true) {
        std::cout << "Informe uma nota entre 0 e 10:\n";
        std::cin >> nota;
        if (nota >= 0 && nota <= 10) {
            break;
        } else {
            std::cout << "Valor invalido\n";
        }
    }
    return 0;
}

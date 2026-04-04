/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    double n;
    std::cout << "Digite um numero:" << "\n";

    if (std::cin >> n) {
        if (n > 0) {
            std::cout << "O numero e positivo" << "\n";
        } else if (n < 0) {
            std::cout << "O numero e negativo" << "\n";
        } else {
            std::cout << "O numero e nulo" << "\n";
        }
    }

    return 0;
}
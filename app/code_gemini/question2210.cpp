/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int P;
    std::cin >> P;
    for (int i = 1; i <= P; ++i) {
        for (int j = 0; j < P - i; ++j) {
            std::cout << ".";
        }
        if (i == 1) {
            std::cout << "*";
        } else {
            std::cout << "*";
            for (int k = 0; k < 2 * i - 3; ++k) {
                std::cout << "-";
            }
            std::cout << "*";
        }
        for (int j = 0; j < P - i; ++j) {
            std::cout << ".";
        }
        std::cout << "\n";
    }
    return 0;
}

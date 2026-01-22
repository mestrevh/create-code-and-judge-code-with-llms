/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    char limit_char;
    std::cin >> limit_char;

    int n = limit_char - 'A';

    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j < n - i; ++j) {
            std::cout << ".";
        }

        for (char c = 'A'; c <= 'A' + i; ++c) {
            std::cout << c;
        }

        for (char c = 'A' + i - 1; c >= 'A'; --c) {
            std::cout << c;
        }

        for (int j = 0; j < n - i; ++j) {
            std::cout << ".";
        }

        std::cout << '\n';
    }

    return 0;
}

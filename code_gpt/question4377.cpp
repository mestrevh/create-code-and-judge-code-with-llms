/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

int main() {
    int n;
    char k;
    std::cin >> n >> k;

    if (k == 'I') {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < 2 * i; ++j) std::cout << ' ';
            for (int j = 0; j < 2 * (n - i) - 1; ++j) std::cout << '*';
            std::cout << std::endl;
        }
    } else if (k == 'S') {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < 2 * (n - i - 1); ++j) std::cout << ' ';
            for (int j = 0; j < 2 * i + 1; ++j) std::cout << '*';
            std::cout << std::endl;
        }
    } else if (k == 'T') {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < 2 * (n - i - 1); ++j) std::cout << ' ';
            for (int j = 0; j < 2 * i + 1; ++j) std::cout << '*';
            std::cout << std::endl;
        }
        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j < 2 * (n - i); ++j) std::cout << ' ';
            for (int j = 0; j < 2 * i - 1; ++j) std::cout << '*';
            std::cout << std::endl;
        }
    }

    return 0;
}

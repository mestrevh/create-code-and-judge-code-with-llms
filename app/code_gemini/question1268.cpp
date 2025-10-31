/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int n;
    std::cin >> n;
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < n - i + 1; ++j) {
            std::cout << '.';
        }
        for (int j = 0; j < 2 * i - 1; ++j) {
            std::cout << '*';
        }
        std::cout << '\n';
    }
    for (int i = n; i >= 1; --i) {
        for (int j = 0; j < n - i + 1; ++j) {
            std::cout << '.';
        }
        for (int j = 0; j < 2 * i - 1; ++j) {
            std::cout << '*';
        }
        std::cout << '\n';
    }
    return 0;
}

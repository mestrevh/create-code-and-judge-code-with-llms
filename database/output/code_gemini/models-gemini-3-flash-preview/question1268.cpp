/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    if (std::cin >> n) {
        for (int i = 1; i <= n; ++i) {
            std::cout << std::string(n - i + 1, '.') << std::string(2 * i - 1, '*') << "\n";
        }
        for (int i = n; i >= 1; --i) {
            std::cout << std::string(n - i + 1, '.') << std::string(2 * i - 1, '*') << "\n";
        }
    }

    return 0;
}
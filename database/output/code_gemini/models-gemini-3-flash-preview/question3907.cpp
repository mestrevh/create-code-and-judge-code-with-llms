/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    if (!(std::cin >> n)) {
        return 0;
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < i; ++j) {
            std::cout << "* ";
        }
        std::cout << "\n";
    }

    for (int i = n - 1; i >= 1; --i) {
        for (int j = 0; j < i; ++j) {
            std::cout << "* ";
        }
        std::cout << "\n";
    }

    return 0;
}
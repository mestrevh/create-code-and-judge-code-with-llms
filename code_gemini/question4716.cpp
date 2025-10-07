/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

void piramideNumerica(int n) {
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= i; ++j) {
            std::cout << i;
            if (j < i) {
                std::cout << " ";
            }
        }
        std::cout << '\n';
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int n;
    std::cin >> n;
    piramideNumerica(n);
    return 0;
}

/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <cmath>
#include <vector>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int n;
    std::cin >> n;
    int dim = 2 * n + 1;
    for (int i = 0; i < dim; ++i) {
        for (int j = 0; j < dim; ++j) {
            if (std::abs(n - i) + std::abs(n - j) < n) {
                std::cout << '.';
            } else {
                std::cout << '*';
            }
        }
        std::cout << '\n';
    }
    return 0;
}

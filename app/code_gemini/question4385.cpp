/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int n, capacidade;
    while (std::cin >> n >> capacidade) {
        while (n > capacidade) {
            std::cout << capacidade << "\n";
            n -= capacidade;
        }
        if (n > 0) {
            std::cout << n << "\n";
        }
    }
    return 0;
}

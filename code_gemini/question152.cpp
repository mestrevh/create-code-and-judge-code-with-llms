/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;
    std::vector<int> numbers(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> numbers[i];
    }

    // a) Ordem inversa
    for (int i = n - 1; i >= 0; --i) {
        std::cout << numbers[i] << (i > 0 ? " " : "");
    }
    std::cout << "\n";

    // b) Deslocamento para a esquerda
    if (n > 0) {
        for (int i = 1; i < n; ++i) {
            std::cout << numbers[i] << " ";
        }
        std::cout << numbers[0];
    }
    std::cout << "\n";

    // c) Ordenado em ordem decrescente
    std::sort(numbers.begin(), numbers.end(), std::greater<int>());
    for (int i = 0; i < n; ++i) {
        std::cout << numbers[i] << (i < n - 1 ? " " : "");
    }
    std::cout << "\n";

    return 0;
}

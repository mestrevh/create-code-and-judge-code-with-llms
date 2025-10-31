/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;

    if (n > 0) {
        std::vector<int> numeros(n);
        for (int i = 0; i < n; ++i) {
            std::cin >> numeros[i];
        }

        std::sort(numeros.begin(), numeros.end());

        for (int i = 0; i < n; ++i) {
            std::cout << "[" << numeros[i] << "]";
        }
    }

    std::cout << std::endl;

    return 0;
}

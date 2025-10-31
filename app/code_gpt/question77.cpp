/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n;
    std::cin >> n;
    std::vector<int> numeros(n);

    for (int i = 0; i < n; ++i) {
        std::cin >> numeros[i];
    }

    std::sort(numeros.begin(), numeros.end());

    for (int i = 0; i < n; ++i) {
        std::cout << "[" << numeros[i] << "]";
    }
    std::cout << std::endl;

    return 0;
}

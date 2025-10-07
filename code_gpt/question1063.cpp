/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <algorithm>
#include <array>

int main() {
    std::array<int, 3> notas;
    for (int i = 0; i < 3; ++i) {
        std::cin >> notas[i];
    }
    std::sort(notas.begin(), notas.end());
    for (const auto& nota : notas) {
        std::cout << nota << std::endl;
    }
    return 0;
}

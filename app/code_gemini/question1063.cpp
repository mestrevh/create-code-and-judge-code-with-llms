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
    std::vector<int> notas(3);
    for (int i = 0; i < 3; ++i) {
        std::cin >> notas[i];
    }
    std::sort(notas.begin(), notas.end());
    for (int i = 0; i < 3; ++i) {
        std::cout << notas[i] << "\n";
    }
    return 0;
}

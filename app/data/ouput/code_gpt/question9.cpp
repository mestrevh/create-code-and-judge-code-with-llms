/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n;
    while (std::cin >> n && n != 0) {
        std::vector<char> caracteres(n);
        std::cin >> std::noskipws; // não pular espaços em branco
        for (int i = 0; i < n; ++i) {
            std::cin >> caracteres[i];
        }
        std::reverse(caracteres.begin(), caracteres.end());
        for (char c : caracteres) {
            std::cout << c;
        }
        std::cout << std::endl;
    }
    return 0;
}

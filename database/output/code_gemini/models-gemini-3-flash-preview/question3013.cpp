/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    double largura, comprimento;
    while (std::cin >> largura >> comprimento) {
        std::cout << std::fixed << std::setprecision(2) << (largura * comprimento) << "\n";
    }

    return 0;
}
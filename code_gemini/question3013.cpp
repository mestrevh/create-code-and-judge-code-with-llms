/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    double largura, comprimento;
    std::cin >> largura >> comprimento;

    double area = largura * comprimento;

    std::cout << std::fixed << std::setprecision(2) << area << std::endl;

    return 0;
}

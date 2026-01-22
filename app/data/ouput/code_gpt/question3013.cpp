/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>

int main() {
    double largura, comprimento;
    std::cin >> largura >> comprimento;
    double area = largura * comprimento;
    std::cout << std::fixed << std::setprecision(2) << area << std::endl;
    return 0;
}

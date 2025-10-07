/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <cmath>
#include <iomanip>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    double largura, altura;
    std::cin >> largura >> altura;
    double diagonal = std::sqrt(largura * largura + altura * altura);
    std::cout << diagonal << std::endl;
    return 0;
}

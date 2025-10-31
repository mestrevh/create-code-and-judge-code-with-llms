/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <algorithm>
#include <iomanip>

int main() {
    double a, b;
    std::cout << "Digite um numero:" << std::endl;
    std::cin >> a;
    std::cout << "Digite outro numero:" << std::endl;
    std::cin >> b;
    double maior = std::max(a, b);
    std::cout << "Maior numero: " << std::fixed << std::setprecision(1) << maior << std::endl;
    return 0;
}

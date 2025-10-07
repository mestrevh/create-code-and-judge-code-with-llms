/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>

int main() {
    double a, b, c;

    std::cout << "Digite um numero:" << std::endl;
    std::cin >> a;

    std::cout << "Digite outro numero:" << std::endl;
    std::cin >> b;

    std::cout << "Digite outro numero:" << std::endl;
    std::cin >> c;

    double maior = std::max({a, b, c});

    std::cout << std::fixed << std::setprecision(1);
    std::cout << "Maior numero: " << maior << std::endl;

    return 0;
}

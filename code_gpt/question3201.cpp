/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <cmath>

int main() {
    double a, b, c;
    std::cin >> a >> b >> c;
    double soma_quadrados = pow(a, 2) + pow(b, 2) + pow(c, 2);
    double quadrado_soma = pow(a + b + c, 2);
    std::cout << soma_quadrados << std::endl;
    std::cout << quadrado_soma << std::endl;
    return 0;
}

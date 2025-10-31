/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <cmath>
#include <iomanip>

int main() {
    double xa, ya, xb, yb;
    std::cin >> xa >> ya >> xb >> yb;
    double distancia = std::sqrt(std::pow(xb - xa, 2) + std::pow(yb - ya, 2));
    std::cout << std::fixed << std::setprecision(1) << distancia << std::endl;
    return 0;
}

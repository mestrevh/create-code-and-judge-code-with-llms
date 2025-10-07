/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <cmath>
#include <iomanip>

int main() {
    double h, l, L;
    std::cin >> h >> l >> L;
    double a = l * l;
    double A = L * L;
    double volume = (h / 3.0) * (A + a + std::sqrt(A * a));
    std::cout << std::fixed << std::setprecision(1) << volume << std::endl;
    return 0;
}

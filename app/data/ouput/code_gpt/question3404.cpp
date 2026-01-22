/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>
#include <cmath>

int main() {
    double A, B, C;
    std::cin >> A >> B >> C;
    
    double discriminante = B * B - 4 * A * C;
    double x1 = (-B + std::sqrt(discriminante)) / (2 * A);
    double x2 = (-B - std::sqrt(discriminante)) / (2 * A);
    
    std::cout << std::fixed << std::setprecision(2) << std::min(x1, x2) << " " << std::max(x1, x2) << std::endl;
    
    return 0;
}

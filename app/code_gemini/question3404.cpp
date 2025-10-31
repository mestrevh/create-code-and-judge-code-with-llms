/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <cmath>
#include <iomanip>
#include <algorithm>

int main() {
    double a, b, c;
    std::cin >> a >> b >> c;
    
    double delta = b * b - 4 * a * c;
    
    double x1 = (-b - std::sqrt(delta)) / (2 * a);
    double x2 = (-b + std::sqrt(delta)) / (2 * a);
    
    if (x1 > x2) {
        std::swap(x1, x2);
    }

    std::cout << std::fixed << std::setprecision(2);
    std::cout << x1 << " " << x2 << std::endl;
    
    return 0;
}

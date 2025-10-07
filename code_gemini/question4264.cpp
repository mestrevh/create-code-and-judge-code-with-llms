/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <cmath>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    double a, b, c;
    std::cin >> a >> b >> c;
    double delta = (b * b) - (4 * a * c);
    double x1_double = (-b + std::sqrt(delta)) / (2 * a);
    double x2_double = (-b - std::sqrt(delta)) / (2 * a);
    int x1_int = static_cast<int>(x1_double);
    int x2_int = static_cast<int>(x2_double);
    std::cout << "x1 = " << x1_int << std::endl;
    std::cout << "x2 = " << x2_int << std::endl;
    return 0;
}

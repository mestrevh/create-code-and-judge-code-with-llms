/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <cmath>
#include <iomanip>

int main() {
    double theta_degrees, v, g;
    std::cin >> theta_degrees >> v >> g;

    const double PI = acos(-1.0);
    double theta_radians = theta_degrees * PI / 180.0;

    double h = (v * v * std::sin(theta_radians) * std::sin(theta_radians)) / (2.0 * g);

    std::cout << std::fixed << std::setprecision(16) << h << std::endl;

    return 0;
}

/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <cmath>
#include <iomanip>

int main() {
    double x1, y1, z1;
    double x2, y2, z2;

    std::cin >> x1 >> y1 >> z1;
    std::cin >> x2 >> y2 >> z2;

    double distance = std::sqrt(std::pow(x2 - x1, 2) + std::pow(y2 - y1, 2) + std::pow(z2 - z1, 2));

    std::cout << std::fixed << std::setprecision(2) << distance << std::endl;

    return 0;
}

/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <cmath>
#include <iomanip>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    double xA, yA, xB, yB, xC, yC;

    std::cin >> xA;
    std::cin >> yA;
    std::cin >> xB;
    std::cin >> yB;
    std::cin >> xC;
    std::cin >> yC;

    double dist_AB = std::sqrt(std::pow(xB - xA, 2) + std::pow(yB - yA, 2));
    double dist_BC = std::sqrt(std::pow(xC - xB, 2) + std::pow(yC - yB, 2));
    double dist_CA = std::sqrt(std::pow(xA - xC, 2) + std::pow(yA - yC, 2));

    std::cout << std::fixed << std::setprecision(2);

    std::cout << "A-B: " << dist_AB << std::endl;
    std::cout << "B-C: " << dist_BC << std::endl;
    std::cout << "C-A: " << dist_CA << std::endl;

    return 0;
}

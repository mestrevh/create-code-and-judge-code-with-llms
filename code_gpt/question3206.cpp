/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <cmath>

double radians(double degrees) {
    return degrees * M_PI / 180.0;
}

int main() {
    double a, d;
    std::cin >> a >> d;
    double l = d / cos(radians(a));
    std::cout << l << std::endl;
    return 0;
}

/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>
#include <cmath>

int main() {
    double r;
    std::cin >> r;
    double area = M_PI * r * r;
    std::cout << std::fixed << std::setprecision(6) << area << std::endl;
    return 0;
}

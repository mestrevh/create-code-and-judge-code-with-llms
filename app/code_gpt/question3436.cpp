/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>
#include <cmath>

const double PI = 3.14159265358979323846;

double area(double radius) {
    return PI * radius * radius;
}

double perimeter(double radius) {
    return 2 * PI * radius;
}

int main() {
    double radius;
    std::cin >> radius;

    std::cout << std::fixed << std::setprecision(5);
    std::cout << area(radius) << std::endl;
    std::cout << perimeter(radius) << std::endl;

    return 0;
}

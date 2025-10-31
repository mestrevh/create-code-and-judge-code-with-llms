/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <cmath>
#include <iomanip>

struct Point {
    double x, y;
};

double calculateAngle(Point a, Point b, Point c) {
    double abx = a.x - b.x;
    double aby = a.y - b.y;
    double bcx = c.x - b.x;
    double bcy = c.y - b.y;

    double dotProduct = abx * bcx + aby * bcy;
    double magAB = sqrt(abx * abx + aby * aby);
    double magBC = sqrt(bcx * bcx + bcy * bcy);

    double cosTheta = dotProduct / (magAB * magBC);
    return acos(cosTheta) * (180.0 / M_PI);
}

int main() {
    Point a, b, c;
    std::cin >> a.x >> a.y;
    std::cin >> b.x >> b.y;
    std::cin >> c.x >> c.y;

    double angle = calculateAngle(a, b, c);
    std::cout << std::fixed << std::setprecision(2) << angle << std::endl;

    return 0;
}

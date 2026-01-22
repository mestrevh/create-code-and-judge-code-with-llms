/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <cmath>
#include <iomanip>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    double x, y, t;

    std::cout << std::fixed << std::setprecision(2);

    while (std::cin >> x >> y >> t) {
        double angle_rad = t * M_PI / 180.0;

        double new_x = x * cos(angle_rad) - y * sin(angle_rad);
        double new_y = x * sin(angle_rad) + y * cos(angle_rad);

        if (std::abs(new_x) < 1e-9) new_x = 0.0;
        if (std::abs(new_y) < 1e-9) new_y = 0.0;

        std::cout << new_x << " " << new_y << std::endl;
    }

    return 0;
}

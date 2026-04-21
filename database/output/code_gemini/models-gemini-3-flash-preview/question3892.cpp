/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <cmath>
#include <iomanip>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    long double x1, y1, z1, x2, y2, z2;
    if (std::cin >> x1 >> y1 >> z1 >> x2 >> y2 >> z2) {
        long double dx = x1 - x2;
        long double dy = y1 - y2;
        long double dz = z1 - z2;
        long double distance = std::sqrt(dx * dx + dy * dy + dz * dz);
        std::cout << std::fixed << std::setprecision(16) << distance << std::endl;
    }

    return 0;
}
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

    double xA, yA, xB, yB;
    if (!(std::cin >> xA >> yA >> xB >> yB)) return 0;

    double dx = xB - xA;
    double dy = yB - yA;
    double distance = std::sqrt(dx * dx + dy * dy);

    std::cout << std::fixed << std::setprecision(1) << distance << std::endl;

    return 0;
}
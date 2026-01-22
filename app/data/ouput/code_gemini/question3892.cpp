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

    double xa, ya, za;
    double xb, yb, zb;

    std::cin >> xa >> ya >> za;
    std::cin >> xb >> yb >> zb;

    double dx = xb - xa;
    double dy = yb - ya;
    double dz = zb - za;

    double distance = std::sqrt(dx * dx + dy * dy + dz * dz);

    std::cout << std::fixed << std::setprecision(16) << distance << std::endl;

    return 0;
}

/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <cmath>
#include <iomanip>

double distancia(double xa, double ya, double xb, double yb) {
    return std::sqrt(std::pow(xb - xa, 2) + std::pow(yb - ya, 2));
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    if (!(std::cin >> n)) return 0;

    std::cout << std::fixed << std::setprecision(2);

    while (n--) {
        double xa, ya, xb, yb;
        if (std::cin >> xa >> ya >> xb >> yb) {
            std::cout << distancia(xa, ya, xb, yb) << "\n";
        }
    }

    return 0;
}
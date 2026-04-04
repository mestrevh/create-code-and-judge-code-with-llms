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

    double theta, v, g;
    if (std::cin >> theta >> v >> g) {
        if (g == 0.0) {
            std::cout << 0.0 << std::endl;
        } else {
            double pi = std::acos(-1.0);
            double rad = theta * (pi / 180.0);
            double vy = v * std::sin(rad);
            double h = (vy * vy) / (2.0 * g);
            
            if (v == 0.0 || std::sin(rad) == 0.0) {
                h = 0.0;
            }
            
            std::cout << std::setprecision(16) << h << std::endl;
        }
    }

    return 0;
}
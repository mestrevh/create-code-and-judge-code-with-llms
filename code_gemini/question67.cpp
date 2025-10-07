/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <cmath>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    double x, y;

    while (std::cin >> x >> y) {
        double ax = std::abs(x);
        double ay = std::abs(y);

        bool is_interior = (ax < 2.0 && ay <= 4.0) || 
                           (ax > 2.0 && ax <= 3.0 && ay <= (-4.0 * ax + 12.0)) || 
                           (ax == 2.0 && ay == 4.0);
        
        if (is_interior) {
            std::cout << "INTERIOR\n";
        } else {
            std::cout << "EXTERIOR\n";
        }
    }

    return 0;
}

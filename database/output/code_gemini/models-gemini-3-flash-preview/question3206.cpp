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

    double a, d;
    if (std::cin >> a >> d) {
        // Convert degrees to radians
        // Formula: radians = degrees * (pi / 180)
        double pi = std::acos(-1.0);
        double radians = a * (pi / 180.0);

        // Given: cos(a) = adjacent / hypotenuse
        // Adjacent = distance from wall (d)
        // Hypotenuse = length of the ladder (L)
        // L = d / cos(a)
        double ladder = d / std::cos(radians);

        // Output with high precision to match test cases
        std::cout << std::setprecision(17) << ladder << std::endl;
    }

    return 0;
}
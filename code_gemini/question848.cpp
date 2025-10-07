/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>
#include <cmath>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    const double PI = 3.1416;
    double R;

    std::cin >> R;

    double area = 4.0 * PI * R * R;
    double volume = (4.0 / 3.0) * PI * R * R * R;

    std::cout << std::fixed << std::setprecision(2);
    std::cout << area << std::endl;
    std::cout << volume << std::endl;

    return 0;
}

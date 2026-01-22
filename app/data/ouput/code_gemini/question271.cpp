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

    const double PI = 3.14159;
    double raio_cm;

    std::cin >> raio_cm;

    double raio_m = raio_cm / 100.0;
    double area = PI * raio_m * raio_m;

    std::cout << std::fixed << std::setprecision(4);
    std::cout << "Area = " << area << std::endl;

    return 0;
}

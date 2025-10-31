/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int x, y, z;
    const double PI = 3.14159;

    std::cin >> x >> y >> z;

    std::cout << std::fixed << std::setprecision(2);

    // Saída 1 - Área do triângulo retângulo
    double area_triangulo = (double)(x * y) / 2.0;
    std::cout << area_triangulo << std::endl;

    // Saída 2 - Área do círculo
    double area_circulo = PI * z * z;
    std::cout << area_circulo << std::endl;

    // Saída 3 - Área do trapézio
    double area_trapezio = (double)(x + y) * z / 2.0;
    std::cout << area_trapezio << std::endl;

    return 0;
}

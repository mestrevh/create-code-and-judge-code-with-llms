/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>

int main() {
    double a, b, c;
    std::cin >> a >> b >> c;

    const double PI = 3.14159;

    double area_triangulo = (a * c) / 2.0;
    double area_circulo = PI * c * c;
    double area_trapezio = ((a + b) * c) / 2.0;
    double area_quadrado = b * b;
    double area_retangulo = a * b;

    std::cout << std::fixed << std::setprecision(3);

    std::cout << "TRIANGULO: " << area_triangulo << std::endl;
    std::cout << "CIRCULO: " << area_circulo << std::endl;
    std::cout << "TRAPEZIO: " << area_trapezio << std::endl;
    std::cout << "QUADRADO: " << area_quadrado << std::endl;
    std::cout << "RETANGULO: " << area_retangulo << std::endl;

    return 0;
}

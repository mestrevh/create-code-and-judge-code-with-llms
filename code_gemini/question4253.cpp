/*
Código criado pelo Gemini Pro 1.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::string figura;
    std::cin >> figura;

    double area = 0.0;
    
    if (figura == "retangulo") {
        double base, altura;
        std::cin >> base >> altura;
        area = base * altura;
    } else if (figura == "triangulo") {
        double base, altura;
        std::cin >> base >> altura;
        area = (base * altura) / 2.0;
    } else if (figura == "trapezio") {
        double base_maior, base_menor, altura;
        std::cin >> base_maior >> base_menor >> altura;
        area = ((base_maior + base_menor) * altura) / 2.0;
    } else if (figura == "circulo") {
        double raio;
        const double pi = 3.1415;
        std::cin >> raio;
        area = pi * raio * raio;
    }

    std::cout << std::fixed << std::setprecision(2) << area << std::endl;

    return 0;
}

/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>
#include <cctype>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    char shape_char;
    double value;

    std::cin >> shape_char;
    std::cin >> value;

    if (value <= 0) {
        std::cout << "Entrada invalida!" << std::endl;
        return 0;
    }

    shape_char = std::toupper(shape_char);

    double area;

    if (shape_char == 'C') {
        area = 3.141 * value * value;
        std::cout << std::fixed << std::setprecision(2) << area << std::endl;
        std::cout << "Circulo" << std::endl;
    } else if (shape_char == 'Q') {
        area = value * value;
        std::cout << std::fixed << std::setprecision(2) << area << std::endl;
        std::cout << "Quadrado" << std::endl;
    } else if (shape_char == 'T') {
        area = (value * value * 1.7) / 4.0;
        std::cout << std::fixed << std::setprecision(2) << area << std::endl;
        std::cout << "Triangulo equilatero" << std::endl;
    } else {
        std::cout << "Entrada invalida!" << std::endl;
    }

    return 0;
}

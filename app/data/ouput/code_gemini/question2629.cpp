/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

int main() {
    double a, b, c;

    std::cout << "Digite o comprimento do lado A:\n";
    std::cin >> a;

    std::cout << "Digite o comprimento do lado B:\n";
    std::cin >> b;

    std::cout << "Digite o comprimento do lado C:\n";
    std::cin >> c;

    if (a == b && b == c) {
        std::cout << "Este e um triangulo equilatero.\n";
    } else if (a == b || a == c || b == c) {
        std::cout << "Este e um triangulo isosceles.\n";
    } else {
        std::cout << "Este e um triangulo escaleno.\n";
    }

    return 0;
}

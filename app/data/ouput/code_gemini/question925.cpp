/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    double a, b, c;
    
    std::cin >> a >> b >> c;

    std::cout << "Informe o comprimento do primeiro lado do triangulo:\n";
    std::cout << "Informe o comprimento do segundo lado do triangulo:\n";
    std::cout << "Informe o comprimento do terceiro lado do triangulo:\n";

    if (a + b > c && a + c > b && b + c > a) {
        std::cout << "Os lados informados podem formar um triangulo\n";
        if (a == b && b == c) {
            std::cout << "Triangulo Equilatero\n";
        } else if (a == b || a == c || b == c) {
            std::cout << "Triangulo Isosceles\n";
        } else {
            std::cout << "Triangulo Escaleno\n";
        }
    } else {
        std::cout << "Os lados informados nao podem formar um triangulo\n";
    }

    return 0;
}

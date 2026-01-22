/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <algorithm>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    double a, b, c;
    std::cin >> a >> b >> c;

    if (a < b + c && b < a + c && c < a + b) {
        if (a == b && b == c) {
            std::cout << "Equilatero" << std::endl;
        } else if (a == b || b == c || a == c) {
            std::cout << "Isosceles" << std::endl;
        } else {
            std::cout << "Escaleno" << std::endl;
        }
    } else {
        std::cout << "Nao eh triangulo" << std::endl;
    }

    return 0;
}

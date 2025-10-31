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
    if (a == b && b == c) {
        std::cout << "equilatero\n";
    } else if (a == b || a == c || b == c) {
        std::cout << "isosceles\n";
    } else {
        std::cout << "escaleno\n";
    }
    return 0;
}

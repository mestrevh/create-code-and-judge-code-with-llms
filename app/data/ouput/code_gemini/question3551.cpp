/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int a, b, c;
    std::cin >> a >> b >> c;
    if (a + b <= c || a + c <= b || b + c <= a) {
        std::cout << "nao eh triangulo\n";
    } else if (a == b && b == c) {
        std::cout << "eh equilatero\n";
    } else if (a == b || a == c || b == c) {
        std::cout << "eh isosceles\n";
    } else {
        std::cout << "eh escaleno\n";
    }
    return 0;
}

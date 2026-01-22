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
    if (a + b > c && a + c > b && b + c > a) {
        if (a == b && b == c) {
            std::cout << "EQUILATERO\n";
        } else if (a == b || b == c || a == c) {
            std::cout << "ISOSCELES\n";
        } else {
            std::cout << "ESCALENO\n";
        }
    } else {
        std::cout << "-\n";
    }
    return 0;
}

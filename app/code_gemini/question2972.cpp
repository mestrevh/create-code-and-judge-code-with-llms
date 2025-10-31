/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <cmath>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    long double x;
    std::cin >> x;
    int exponent = floor(log10l(x));
    std::cout << exponent << std::endl;
    return 0;
}

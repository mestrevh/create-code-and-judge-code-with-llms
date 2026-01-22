/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <algorithm>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int a, b, c;
    std::cin >> a >> b >> c;

    if (a < b) {
        std::swap(a, b);
    }
    if (a < c) {
        std::swap(a, c);
    }
    if (b < c) {
        std::swap(b, c);
    }

    std::cout << a << "\n";
    std::cout << b << "\n";
    std::cout << c << "\n";

    return 0;
}

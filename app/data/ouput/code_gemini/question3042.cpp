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
    if (a > b && b <= c) {
        std::cout << ":)\n";
    } else if (a < b && b < c && (c - b) >= (b - a)) {
        std::cout << ":)\n";
    } else if (a > b && b > c && (b - c) < (a - b)) {
        std::cout << ":)\n";
    } else if (a == b && b < c) {
        std::cout << ":)\n";
    } else {
        std::cout << ":(\n";
    }
    return 0;
}

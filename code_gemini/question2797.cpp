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
    if (a != b && a != c) {
        std::cout << "A\n";
    } else if (b != a && b != c) {
        std::cout << "B\n";
    } else if (c != a && c != b) {
        std::cout << "C\n";
    } else {
        std::cout << "*\n";
    }
    return 0;
}

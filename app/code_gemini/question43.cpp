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
    if (a == b && b == c) {
        std::cout << 1 << std::endl;
    } else if (a != b && a != c && b != c) {
        std::cout << 2 << std::endl;
    } else {
        std::cout << 3 << std::endl;
    }
    return 0;
}

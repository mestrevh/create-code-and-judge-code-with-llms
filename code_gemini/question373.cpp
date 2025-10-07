/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    long long a, b, c, d;
    std::cin >> a >> b >> c >> d;
    if (a * b == c * d || a * c == b * d || a * d == b * c) {
        std::cout << "S\n";
    } else {
        std::cout << "N\n";
    }
    return 0;
}

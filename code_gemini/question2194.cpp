/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <cmath>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    long long a, b, s;
    std::cin >> a >> b >> s;
    long long dist = std::abs(a) + std::abs(b);
    if (s < dist) {
        std::cout << "No\n";
    } else {
        if ((s - dist) % 2 == 0) {
            std::cout << "Yes\n";
        } else {
            std::cout << "No\n";
        }
    }
    return 0;
}

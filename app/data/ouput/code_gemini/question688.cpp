/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <numeric>
#include <cmath>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    long long a, b, c;
    std::cin >> a >> b >> c;
    if (a == 0 && b == 0) {
        if (c == 0) {
            std::cout << "S\n";
        } else {
            std::cout << "N\n";
        }
    } else {
        if (c % std::gcd(a, b) == 0) {
            std::cout << "S\n";
        } else {
            std::cout << "N\n";
        }
    }
    return 0;
}

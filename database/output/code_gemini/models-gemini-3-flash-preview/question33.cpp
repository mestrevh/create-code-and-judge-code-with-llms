/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <numeric>
#include <cmath>

long long get_gcd(long long a, long long b) {
    a = std::abs(a);
    b = std::abs(b);
    while (b) {
        a %= b;
        std::swap(a, b);
    }
    return a;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    long long a, b, c, d;
    char s1, op, s2;

    while (std::cin >> a >> s1 >> b >> op >> c >> s2 >> d) {
        if (b == 0 || d == 0) {
            std::cout << "entrada invalida!" << std::endl;
            continue;
        }

        long long num = a * d + c * b;
        long long den = b * d;

        if (num == 0) {
            std::cout << "0/1" << std::endl;
            continue;
        }

        long long common = get_gcd(num, den);
        num /= common;
        den /= common;

        if (den < 0) {
            num = -num;
            den = -den;
        }

        std::cout << num << "/" << den << std::endl;
    }

    return 0;
}
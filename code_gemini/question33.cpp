/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <numeric>
#include <cmath>

long long gcd(long long a, long long b) {
    return std::abs(std::gcd(a, b));
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    long long a, b, c, d;
    char slash1, plus, slash2;

    if (!(std::cin >> a >> slash1 >> b >> plus >> c >> slash2 >> d)) {
        return 1;
    }

    if (b == 0 || d == 0) {
        std::cout << "entrada invalida!" << std::endl;
        return 0;
    }

    long long num = a * d + c * b;
    long long den = b * d;

    if (num == 0) {
        den = 1;
    } else {
        long long common_divisor = gcd(num, den);
        num /= common_divisor;
        den /= common_divisor;
    }

    if (den < 0) {
        den = -den;
        num = -num;
    }

    std::cout << num << "/" << den << std::endl;

    return 0;
}

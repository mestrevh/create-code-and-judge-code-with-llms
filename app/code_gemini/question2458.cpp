/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

long long countDivisors(long long n) {
    if (n == 0) {
        return 0;
    }
    if (n == 1) {
        return 1;
    }

    long long total_divisors = 1;

    int exponent = 0;
    while (n % 2 == 0) {
        exponent++;
        n /= 2;
    }
    if (exponent > 0) {
        total_divisors *= (exponent + 1);
    }

    for (long long i = 3; i * i <= n; i += 2) {
        exponent = 0;
        while (n % i == 0) {
            exponent++;
            n /= i;
        }
        if (exponent > 0) {
            total_divisors *= (exponent + 1);
        }
    }

    if (n > 1) {
        total_divisors *= 2;
    }

    return total_divisors;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    long long p;
    while (std::cin >> p) {
        std::cout << countDivisors(p) << "\n";
    }

    return 0;
}

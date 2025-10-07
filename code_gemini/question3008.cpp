/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <numeric>

long long largest_prime_factor(long long n) {
    long long max_prime = -1;

    while (n % 2 == 0) {
        max_prime = 2;
        n >>= 1;
    }

    for (long long i = 3; i * i <= n; i += 2) {
        while (n % i == 0) {
            max_prime = i;
            n = n / i;
        }
    }

    if (n > 2) {
        max_prime = n;
    }

    return max_prime;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    long long x, y;
    std::cin >> x >> y;

    long long g = std::gcd(x, y);

    if (g == 1) {
        std::cout << -1 << '\n';
    } else {
        std::cout << largest_prime_factor(g) << '\n';
    }

    return 0;
}

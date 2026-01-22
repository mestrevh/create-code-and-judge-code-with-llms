/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <numeric>

long long gcd(long long a, long long b) {
    while (b) {
        a %= b;
        std::swap(a, b);
    }
    return a;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    long long m, n;
    std::cin >> m >> n;

    long long common_divisor = gcd(m, n);

    long long m_prime = m / common_divisor;
    long long n_prime = n / common_divisor;

    if (m_prime % 2 != 0 && n_prime % 2 != 0) {
        std::cout << common_divisor << std::endl;
    } else {
        std::cout << 0 << std::endl;
    }

    return 0;
}

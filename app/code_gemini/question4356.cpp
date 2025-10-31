/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <cmath>

void prime_factors(long long n) {
    if (n == 1) {
        std::cout << 1;
        return;
    }

    std::vector<long long> factors;
    while (n % 2 == 0) {
        factors.push_back(2);
        n = n / 2;
    }

    for (long long i = 3; i * i <= n; i = i + 2) {
        while (n % i == 0) {
            factors.push_back(i);
            n = n / i;
        }
    }

    if (n > 2) {
        factors.push_back(n);
    }

    for (size_t i = 0; i < factors.size(); ++i) {
        std::cout << factors[i] << (i == factors.size() - 1 ? "" : " ");
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    long long n;
    std::cin >> n;

    prime_factors(n);
    std::cout << std::endl;

    return 0;
}

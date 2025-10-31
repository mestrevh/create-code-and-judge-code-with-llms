/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

bool is_prime(int n) {
    if (n <= 1) {
        return false;
    }
    for (int i = 2; i * i <= n; ++i) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;

    std::vector<int> primes;
    int num;

    for (int i = 0; i < n * n; ++i) {
        std::cin >> num;
        if (is_prime(num)) {
            primes.push_back(num);
        }
    }

    std::sort(primes.begin(), primes.end());

    for (size_t i = 0; i < primes.size(); ++i) {
        std::cout << primes[i] << (i == primes.size() - 1 ? "" : " ");
    }
    std::cout << std::endl;

    return 0;
}

/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <cmath>

bool is_prime(int n) {
    if (n <= 1) return false;
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) return false;
    }
    return true;
}

std::vector<int> mersenne_sequence(int limit) {
    std::vector<int> primes;
    for (int n = 2; n < limit; n++) {
        if (is_prime(n) && is_prime((1 << n) - 1)) {
            primes.push_back(n);
        }
    }
    return primes;
}

int main() {
    int m;
    while (true) {
        std::cin >> m;
        if (m < 0) break;
        std::vector<int> seq = mersenne_sequence(m);
        for (int num : seq) {
            std::cout << num << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}

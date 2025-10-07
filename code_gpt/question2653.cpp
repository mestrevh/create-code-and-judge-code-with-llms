/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>

bool isPrime(int num) {
    if (num < 2) return false;
    for (int i = 2; i * i <= num; ++i) {
        if (num % i == 0) return false;
    }
    return true;
}

int main() {
    int n;
    std::cin >> n;
    std::vector<int> non_primes;

    for (int i = 1; i <= n; ++i) {
        if (!isPrime(i)) {
            non_primes.push_back(i);
        }
    }

    for (size_t i = 0; i < non_primes.size(); ++i) {
        std::cout << non_primes[i];
        if (i < non_primes.size() - 1) std::cout << " ";
    }
    std::cout << std::endl;

    return 0;
}

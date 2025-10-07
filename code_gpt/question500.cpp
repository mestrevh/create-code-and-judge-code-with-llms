/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm>

bool isPrime(int n) {
    if (n <= 1) return false;
    for (int i = 2; i * i <= n; ++i) {
        if (n % i == 0) return false;
    }
    return true;
}

int main() {
    int a, b;
    std::cin >> a >> b;
    int low = std::min(a, b);
    int high = std::max(a, b);
    std::vector<int> primes;

    for (int i = high; i >= low; --i) {
        if (isPrime(i)) {
            primes.push_back(i);
        }
    }

    for (int prime : primes) {
        std::cout << prime << std::endl;
    }
    return 0;
}

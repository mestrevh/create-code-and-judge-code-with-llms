/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>
#include <vector>

bool is_prime(int num) {
    if (num <= 1) return false;
    for (int i = 2; i * i <= num; ++i) {
        if (num % i == 0) return false;
    }
    return true;
}

int main() {
    int n;
    std::cin >> n;
    std::vector<std::pair<int, int>> twin_primes;
    for (int i = 3, count = 0; count < n; i++) {
        if (is_prime(i) && is_prime(i + 2)) {
            twin_primes.emplace_back(i, i + 2);
            count++;
        }
    }
    double sum = 0.0;
    for (const auto& p : twin_primes) {
        sum += 1.0 / p.first + 1.0 / p.second;
    }
    std::cout << std::fixed << std::setprecision(10) << sum << std::endl;
    return 0;
}

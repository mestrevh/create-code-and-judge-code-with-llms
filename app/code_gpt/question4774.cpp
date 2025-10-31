/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm>

bool isPrime(int n) {
    if (n <= 1) return false;
    for (int i = 2; i * i <= n; ++i)
        if (n % i == 0) return false;
    return true;
}

int sumOfDivisors(int n) {
    int sum = 0;
    for (int i = 1; i < n; ++i) {
        if (n % i == 0) sum += i;
    }
    return sum;
}

int main() {
    std::vector<int> primes, nonPrimes;
    int num;

    while (std::cin >> num && num > 0) {
        if (isPrime(num)) {
            primes.push_back(num);
        } else {
            nonPrimes.push_back(sumOfDivisors(num));
        }
    }

    if (!primes.empty()) {
        int maxPrime = *std::max_element(primes.begin(), primes.end());
        std::cout << "Maior numero primo: " << maxPrime << std::endl;

        if (!nonPrimes.empty()) {
            int minSumDiv = *std::min_element(nonPrimes.begin(), nonPrimes.end());
            std::cout << "Menor soma dos divisores: " << minSumDiv << std::endl;

            if (maxPrime > 3 * minSumDiv) {
                std::cout << "Deu a logica, Computos campeao!" << std::endl;
            } else {
                std::cout << "eh mafiaaaaa!" << std::endl;
            }
        } else {
            std::cout << "Nenhum numero nao primo foi digitado" << std::endl;
        }
    } else {
        std::cout << "Nenhum numero primo foi digitado" << std::endl;
    }

    return 0;
}

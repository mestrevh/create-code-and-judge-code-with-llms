/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <cmath>

const int MAX_B = 2000;
const int SIEVE_LIMIT = 2100;

std::vector<int> primes;
std::vector<int> zeca_primes;
std::vector<bool> is_prime;

void sieve() {
    is_prime.assign(SIEVE_LIMIT + 1, true);
    is_prime[0] = is_prime[1] = false;
    for (int p = 2; p * p <= SIEVE_LIMIT; ++p) {
        if (is_prime[p]) {
            for (int i = p * p; i <= SIEVE_LIMIT; i += p) {
                is_prime[i] = false;
            }
        }
    }
    for (int p = 2; p <= SIEVE_LIMIT; ++p) {
        if (is_prime[p]) {
            primes.push_back(p);
        }
    }
}

void find_zeca_primes() {
    for (size_t i = 1; i < primes.size() - 1; ++i) {
        if (primes[i] * 2 == primes[i - 1] + primes[i + 1]) {
            if (primes[i] <= MAX_B) {
               zeca_primes.push_back(primes[i]);
            }
        }
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    sieve();
    find_zeca_primes();

    int a, b;
    std::cin >> a >> b;

    int count = 0;
    for (int zp : zeca_primes) {
        if (zp >= a && zp <= b) {
            count++;
        }
    }

    std::cout << count << std::endl;

    return 0;
}

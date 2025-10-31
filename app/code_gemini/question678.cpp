/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <cmath>

const int SIEVE_LIMIT = 1000001;
std::vector<int> prime_count_prefix(SIEVE_LIMIT);

void precompute_primes() {
    std::vector<bool> is_prime(SIEVE_LIMIT, true);
    is_prime[0] = is_prime[1] = false;
    for (int p = 2; p * p < SIEVE_LIMIT; ++p) {
        if (is_prime[p]) {
            for (int i = p * p; i < SIEVE_LIMIT; i += p) {
                is_prime[i] = false;
            }
        }
    }

    prime_count_prefix[0] = 0;
    for (int i = 1; i < SIEVE_LIMIT; ++i) {
        prime_count_prefix[i] = prime_count_prefix[i - 1] + (is_prime[i] ? 1 : 0);
    }
}

void solve() {
    long long a, b;
    std::cin >> a >> b;

    long long upper_bound = static_cast<long long>(sqrt(b));
    long long lower_bound = static_cast<long long>(sqrt(a - 1));

    int result = prime_count_prefix[upper_bound] - prime_count_prefix[lower_bound];
    std::cout << result << "\n";
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    precompute_primes();

    int t;
    std::cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}

/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

std::vector<int> primes;

void sieve() {
    const int MAXN = 1001;
    std::vector<bool> is_prime_sieve(MAXN, true);
    is_prime_sieve[0] = is_prime_sieve[1] = false;
    for (int p = 2; p * p < MAXN; ++p) {
        if (is_prime_sieve[p]) {
            for (int i = p * p; i < MAXN; i += p)
                is_prime_sieve[i] = false;
        }
    }
    for (int p = 2; p < MAXN; ++p) {
        if (is_prime_sieve[p]) {
            primes.push_back(p);
        }
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    sieve();

    int L, U;
    std::cin >> L >> U;
    
    int prev_prime = -1;
    std::map<int, int> frequencies;
    
    for (int p : primes) {
        if (p > U) {
            break;
        }
        if (p >= L) {
            if (prev_prime != -1) {
                int diff = p - prev_prime;
                frequencies[diff]++;
            }
            prev_prime = p;
        }
    }

    if (frequencies.empty()) {
        std::cout << "-1\n";
        return 0;
    }

    int champion = -1;
    int max_freq = 0;
    bool tie = false;

    for (auto const& pair : frequencies) {
        int freq = pair.second;
        if (freq > max_freq) {
            max_freq = freq;
            champion = pair.first;
            tie = false;
        } else if (freq == max_freq) {
            tie = true;
        }
    }

    if (tie) {
        std::cout << "-1\n";
    } else {
        std::cout << champion << "\n";
    }

    return 0;
}

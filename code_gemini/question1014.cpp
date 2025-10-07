/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <cmath>

const int MAXN = 100001;
std::vector<bool> is_prime(MAXN, true);
std::vector<int> primes;

void sieve() {
    is_prime[0] = is_prime[1] = false;
    for (int p = 2; p * p < MAXN; ++p) {
        if (is_prime[p]) {
            for (int i = p * p; i < MAXN; i += p)
                is_prime[i] = false;
        }
    }
    for (int p = 2; p < MAXN; ++p) {
        if (is_prime[p]) {
            primes.push_back(p);
        }
    }
}

void solve() {
    int n;
    std::cin >> n;

    if (n > 1 && is_prime[n]) {
        std::cout << "Primo\n";
        return;
    }

    bool almost_prime = false;
    for (int p1 : primes) {
        if ((long long)p1 * p1 > n) {
            break;
        }
        if (n % p1 == 0) {
            int p2 = n / p1;
            if (p1 != p2 && is_prime[p2]) {
                almost_prime = true;
                break;
            }
        }
    }

    if (almost_prime) {
        std::cout << "Quase primo\n";
    } else {
        std::cout << "Nem primo nem quase primo\n";
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    sieve();

    int t;
    std::cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}

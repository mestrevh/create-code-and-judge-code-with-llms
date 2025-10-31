/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <cmath>

const int MAX_X = 10000000;
std::vector<bool> is_prime;

void sieve() {
    is_prime.assign(MAX_X + 1, true);
    is_prime[0] = is_prime[1] = false;
    for (long long p = 2; p <= MAX_X; ++p) {
        if (is_prime[p]) {
            for (long long i = p * p; i <= MAX_X; i += p)
                is_prime[i] = false;
        }
    }
}

void solve() {
    int x;
    std::cin >> x;

    if (x == 1) {
        std::cout << "NO\n";
        return;
    }

    if (is_prime[x]) {
        std::cout << "NO\n";
        return;
    }

    long long s = round(sqrt(x));
    if (s * s == x) {
        if (is_prime[s]) {
            std::cout << "NO\n";
            return;
        }
    }

    std::cout << "YES\n";
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    sieve();

    int n;
    std::cin >> n;
    while (n--) {
        solve();
    }

    return 0;
}

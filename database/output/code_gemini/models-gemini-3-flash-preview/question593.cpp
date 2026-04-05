/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <bitset>

using namespace std;

/**
 * Problem: Rodrigo and his interns
 * Rodrigo drinks from bottles where the number of divisors d(X) >= 4.
 * A bottle is poisoned if d(X) < 4.
 * 
 * Divisor count analysis:
 * d(X) = 1  => X = 1
 * d(X) = 2  => X is a prime number (p)
 * d(X) = 3  => X is the square of a prime number (p^2)
 * For any other X > 1, d(X) >= 4.
 * 
 * Rodrigo drinks (YES) if X is not 1, not prime, and not p^2.
 * Constraints: N <= 10^5, X <= 10^7.
 * Time Complexity: O(MAX log log MAX + N)
 * Space Complexity: O(MAX) bits
 */

const int MAX = 10000000;
bitset<MAX + 1> is_prime;
bitset<MAX + 1> can_drink;

void precompute() {
    // Sieve of Eratosthenes to find all primes up to 10^7
    is_prime.set();
    is_prime[0] = is_prime[1] = 0;
    for (int p = 2; p * p <= MAX; p++) {
        if (is_prime[p]) {
            for (int i = p * p; i <= MAX; i += p) {
                is_prime[i] = 0;
            }
        }
    }

    // Identify numbers Rodrigo can drink
    // Poisoned: {1, p, p^2}
    // Rodrigo drinks (YES) if X is NOT in the poisoned set.
    can_drink.set();
    can_drink[1] = 0; // 1 is poisoned (d(1) = 1 < 4)
    for (int p = 2; p <= MAX; p++) {
        if (is_prime[p]) {
            can_drink[p] = 0; // prime p is poisoned (d(p) = 2 < 4)
            if (1LL * p * p <= MAX) {
                can_drink[(int)(1LL * p * p)] = 0; // p^2 is poisoned (d(p^2) = 3 < 4)
            }
        }
    }
}

int main() {
    // Optimization for faster I/O in competitive programming
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    precompute();

    int N;
    if (!(cin >> N)) return 0;

    while (N--) {
        int X;
        if (!(cin >> X)) break;
        
        // Lookup the precomputed result
        if (can_drink[X]) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }

    return 0;
}
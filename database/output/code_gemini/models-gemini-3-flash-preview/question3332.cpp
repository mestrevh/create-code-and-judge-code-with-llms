/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>

using namespace std;

/**
 * Problem: Os primos de Zeca
 * Description: A Zeca Prime is a prime Pn such that Pn = (P(n-1) + P(n+1)) / 2.
 * We need to count Zeca primes in the range [A, B].
 * Constraints: 2 < A < B <= 2000.
 */

int main() {
    // Standard I/O optimization
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int a, b;
    if (!(cin >> a >> b)) return 0;

    // B is at most 2000. To check if the largest prime near 2000 is a Zeca Prime,
    // we need the next prime after it. 3000 is a safe limit.
    const int LIMIT = 3000;
    vector<bool> is_prime(LIMIT, true);
    is_prime[0] = is_prime[1] = false;

    // Sieve of Eratosthenes O(N log log N)
    for (int p = 2; p * p < LIMIT; p++) {
        if (is_prime[p]) {
            for (int i = p * p; i < LIMIT; i += p)
                is_prime[i] = false;
        }
    }

    // Store all primes in a sorted vector
    vector<int> primes;
    for (int p = 2; p < LIMIT; p++) {
        if (is_prime[p]) {
            primes.push_back(p);
        }
    }

    int zeca_count = 0;
    // Iterate through primes, skipping the first (no Pn-1) and the last (no Pn+1)
    for (size_t i = 1; i < primes.size() - 1; i++) {
        int pn = primes[i];
        
        // Only consider primes within the interval [A, B]
        if (pn >= a && pn <= b) {
            int prev_p = primes[i - 1];
            int next_p = primes[i + 1];
            
            // Zeca Prime condition: Pn = (P(n-1) + P(n+1)) / 2
            // Equivalent to: 2 * Pn = P(n-1) + P(n+1)
            if (2 * pn == prev_p + next_p) {
                zeca_count++;
            }
        }
    }

    cout << zeca_count << endl;

    return 0;
}
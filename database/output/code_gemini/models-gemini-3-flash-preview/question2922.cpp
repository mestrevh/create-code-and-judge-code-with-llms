/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int A, B;
    if (!(cin >> A >> B)) return 0;

    // Primes are precomputed using the Sieve of Eratosthenes up to the upper limit B.
    // The problem states B <= 2000, so a sieve is highly efficient.
    vector<bool> is_prime(B + 1, true);
    if (B >= 0) is_prime[0] = false;
    if (B >= 1) is_prime[1] = false;
    for (int p = 2; p * p <= B; p++) {
        if (is_prime[p]) {
            for (int i = p * p; i <= B; i += p)
                is_prime[i] = false;
        }
    }

    int max_len = 0;

    // Iterate through every number i in the interval [A, B).
    // If i is prime, it could be the start of a sexy prime sequence.
    for (int i = A; i < B; i++) {
        if (is_prime[i]) {
            int current_count = 1;
            int current_val = i;
            
            // A sexy prime sequence is defined by p, p+6, p+12, ... where all are primes.
            // Continue the sequence as long as the next element is within the interval [A, B) and is prime.
            while (current_val + 6 < B && is_prime[current_val + 6]) {
                current_count++;
                current_val += 6;
            }
            
            if (current_count > max_len) {
                max_len = current_count;
            }
        }
    }

    // Output the length of the largest sexy prime sequence found.
    cout << max_len << endl;

    return 0;
}
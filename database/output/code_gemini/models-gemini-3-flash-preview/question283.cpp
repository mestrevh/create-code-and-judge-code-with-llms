/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int L, U;
    if (!(cin >> L >> U)) {
        return 0;
    }

    if (U < 2 || L > U) {
        cout << -1 << endl;
        return 0;
    }

    // Sieve of Eratosthenes up to U
    vector<bool> is_prime(U + 1, true);
    is_prime[0] = is_prime[1] = false;
    for (int p = 2; p * p <= U; p++) {
        if (is_prime[p]) {
            for (int i = p * p; i <= U; i += p) {
                is_prime[i] = false;
            }
        }
    }

    // Collect all primes in the range [L, U]
    vector<int> primes;
    for (int i = L; i <= U; i++) {
        if (is_prime[i]) {
            primes.push_back(i);
        }
    }

    // If there are fewer than 2 primes, no jump champion exists
    if (primes.size() < 2) {
        cout << -1 << endl;
        return 0;
    }

    // Calculate frequencies of differences
    map<int, int> diff_counts;
    int max_freq = 0;
    for (size_t i = 0; i < primes.size() - 1; i++) {
        int diff = primes[i + 1] - primes[i];
        diff_counts[diff]++;
        if (diff_counts[diff] > max_freq) {
            max_freq = diff_counts[diff];
        }
    }

    // Check if the maximum frequency is unique
    int champion = -1;
    int winners = 0;
    for (auto const& [diff, freq] : diff_counts) {
        if (freq == max_freq) {
            champion = diff;
            winners++;
        }
    }

    // If more than one difference has the max frequency, no jumping champion
    if (winners > 1) {
        cout << -1 << endl;
    } else {
        cout << champion << endl;
    }

    return 0;
}
/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * Optimized primality test using trial division up to sqrt(n)
 * with 6k +/- 1 optimization.
 */
bool is_prime(long long n) {
    if (n < 2) return false;
    if (n == 2 || n == 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;
    for (long long i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) return false;
    }
    return true;
}

int main() {
    // Fast I/O optimization
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    // Read n and process the matrix
    while (cin >> n) {
        vector<long long> primes;
        long long total_elements = (long long)n * n;
        
        for (long long i = 0; i < total_elements; ++i) {
            long long val;
            if (!(cin >> val)) break;
            if (is_prime(val)) {
                primes.push_back(val);
            }
        }

        // Sort the collected prime numbers in ascending order
        sort(primes.begin(), primes.end());

        // Output the primes separated by space
        for (size_t i = 0; i < primes.size(); ++i) {
            cout << primes[i] << (i == primes.size() - 1 ? "" : " ");
        }
        cout << "\n";
    }

    return 0;
}
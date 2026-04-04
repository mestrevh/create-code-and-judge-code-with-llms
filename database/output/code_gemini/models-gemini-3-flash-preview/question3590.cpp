/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>

using namespace std;

/**
 * Checks if a number is prime.
 * Optimized with trial division up to sqrt(n).
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
    // Standard I/O optimization for Competitive Programming
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n = 0;
    
    // Read the required amount of prime numbers with validation
    while (cin >> n) {
        if (n >= 2 && n <= 12) {
            break;
        }
        cout << "Informe um valor entre 2 e 12!" << "\n";
    }

    vector<int> found_primes;
    int current_val;

    // Read numbers until the required count of primes is reached
    while (found_primes.size() < (size_t)n && cin >> current_val) {
        if (is_prime(current_val)) {
            found_primes.push_back(current_val);
        }
    }

    // Output the prime numbers separated by a single space
    for (size_t i = 0; i < found_primes.size(); ++i) {
        cout << found_primes[i] << (i == found_primes.size() - 1 ? "" : " ");
    }
    cout << endl;

    return 0;
}
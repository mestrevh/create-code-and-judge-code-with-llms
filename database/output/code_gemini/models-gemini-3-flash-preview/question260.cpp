/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

using namespace std;

/**
 * Highly optimized primality test using trial division.
 * Time complexity: O(sqrt(N)) per query.
 * For N up to 10^14, this approach is sufficient within 10s.
 */
bool is_prime(long long n) {
    if (n < 2) return false;
    if (n == 2 || n == 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;
    
    // Check divisors using 6k +/- 1 rule
    for (long long i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    // Standard I/O optimization for competitive programming
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long n;
    // Process input sequence until -1 is encountered
    while (cin >> n && n != -1) {
        if (is_prime(n)) {
            cout << "1\n";
        } else {
            cout << "0\n";
        }
    }

    return 0;
}
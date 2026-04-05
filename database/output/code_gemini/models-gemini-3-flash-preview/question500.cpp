/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <algorithm>

using namespace std;

/**
 * Optimized primality test using the 6k +/- 1 rule.
 * Complexity: O(sqrt(N))
 */
bool is_prime(long long n) {
    if (n < 2) return false;
    if (n < 4) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;
    for (long long i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) return false;
    }
    return true;
}

int main() {
    // Fast I/O optimization for Competitive Programming
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long a, b;
    if (!(cin >> a >> b)) return 0;

    // Define the boundaries of the interval
    long long upper = max(a, b);
    long long lower = min(a, b);

    // Iterate in descending order as required by the problem
    for (long long i = upper; i >= lower; --i) {
        if (is_prime(i)) {
            cout << i << "\n";
        }
    }

    return 0;
}
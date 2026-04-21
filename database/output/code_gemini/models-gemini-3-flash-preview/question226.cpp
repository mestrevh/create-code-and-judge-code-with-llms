/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

using namespace std;

/**
 * Problem: Sum of all natural multiples of 3 or 5 less than n.
 * Approach: Inclusion-Exclusion Principle with Arithmetic Progression formula.
 * Time Complexity: O(1)
 * Space Complexity: O(1)
 */

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long n;
    if (!(cin >> n)) return 0;

    auto sum_multiples = [&](long long k) -> long long {
        if (n <= k) return 0;
        long long m = (n - 1) / k;
        // Arithmetic series sum: k * (1 + 2 + ... + m) = k * m * (m + 1) / 2
        // Using long long to prevent overflow for large n
        return k * (m * (m + 1) / 2);
    };

    // Result = Sum(multiples of 3) + Sum(multiples of 5) - Sum(multiples of 15)
    long long result = sum_multiples(3) + sum_multiples(5) - sum_multiples(15);

    cout << result << "\n";

    return 0;
}
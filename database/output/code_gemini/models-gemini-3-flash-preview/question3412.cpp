/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <algorithm>

using namespace std;

/**
 * GCD (MDC) implementation using the Euclidean algorithm.
 * Time Complexity: O(log(min(a, b)))
 * Space Complexity: O(1)
 */
long long calculate_gcd(long long a, long long b) {
    while (b) {
        a %= b;
        swap(a, b);
    }
    return a;
}

int main() {
    // Standard competitive programming I/O optimization
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long a, b;
    // Reading input values. Using long long to prevent overflow for large integers.
    if (cin >> a >> b) {
        cout << "MDC=" << calculate_gcd(a, b) << endl;
    }

    return 0;
}
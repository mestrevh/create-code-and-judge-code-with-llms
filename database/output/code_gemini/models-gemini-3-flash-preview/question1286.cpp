/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

using namespace std;

/**
 * Computes the Greatest Common Divisor (MDC) using the recursive Euclidean Algorithm.
 * Time Complexity: O(log(min(a, b)))
 * Space Complexity: O(log(min(a, b))) due to recursion stack
 */
long long mdc(long long a, long long b) {
    if (b == 0) {
        return a;
    }
    return mdc(b, a % b);
}

int main() {
    // Standard I/O optimization for competitive programming
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long a, b;
    // Process input until end of file (EOF)
    while (cin >> a >> b) {
        cout << mdc(a, b) << "\n";
    }

    return 0;
}
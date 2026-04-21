/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

using namespace std;

/**
 * Problem: Fibonacci sequence S_n where S_4 = 2 and S_5 = 3.
 * Based on test cases:
 * n=1 -> 0
 * n=2 -> 1
 * n=3 -> 1
 * n=4 -> 2
 * n=5 -> 3
 * This corresponds to F(n-1) where F(0)=0, F(1)=1, F(2)=1, F(3)=2, F(4)=3.
 * 
 * Complexity: O(N) time, O(1) space.
 */

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long n;
    if (!(cin >> n)) return 0;

    if (n <= 1) {
        cout << 0 << "\n";
        return 0;
    }

    if (n == 2 || n == 3) {
        cout << 1 << "\n";
        return 0;
    }

    // Iterative approach to calculate the n-th Fibonacci value (F_{n-1})
    // For n=4, we need F_3=2. For n=5, we need F_4=3.
    long long a = 1; // Represents S_2 (F_1)
    long long b = 1; // Represents S_3 (F_2)
    long long current = 0;

    for (long long i = 4; i <= n; ++i) {
        current = a + b;
        a = b;
        b = current;
    }

    cout << b << "\n";

    return 0;
}
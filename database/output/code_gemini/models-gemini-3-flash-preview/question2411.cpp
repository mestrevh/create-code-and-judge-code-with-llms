/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

using namespace std;

/**
 * Problem: Digital Root
 * The digital root of a number can be found using the formula:
 * DR(n) = 1 + (n - 1) % 9
 * To find the k-th positive number with digital root x:
 * n = x + (k - 1) * 9
 *
 * Complexity: O(1) per query
 * Total Complexity: O(N)
 */

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;

    while (n--) {
        long long k, x;
        if (!(cin >> k >> x)) break;

        // The formula for the k-th number with digital root x is derived from:
        // x = (n - 1) % 9 + 1
        // x - 1 = (n - 1) % 9
        // n - 1 = (k - 1) * 9 + (x - 1)
        // n = (k - 1) * 9 + x
        long long result = x + (k - 1) * 9;
        cout << result << "\n";
    }

    return 0;
}
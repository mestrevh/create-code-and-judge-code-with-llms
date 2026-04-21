/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <algorithm>

using namespace std;

/**
 * Problem: Resto entre números
 * Logic: Iterate between X and Y (exclusive) and print values where (i % 5) is 2 or 3.
 * Complexity: O(N) where N is the distance between X and Y.
 */

int main() {
    // Optimization for fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int x, y;
    if (!(cin >> x >> y)) {
        return 0;
    }

    // Ensure x is the smaller value
    if (x > y) {
        swap(x, y);
    }

    // Iterate through values strictly between x and y
    for (int i = x + 1; i < y; ++i) {
        int remainder = i % 5;
        // Check condition: remainder of division by 5 is 2 or 3
        if (remainder == 2 || remainder == 3) {
            cout << i << "\n";
        }
    }

    return 0;
}
/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <bitset>

using namespace std;

/**
 * Problem: Intersection of two arrays of size M.
 * Elements K are in the range (0, 10000).
 * Output unique common elements in ascending order, each followed by a newline.
 * 
 * Time Complexity: O(M + max_K)
 * Space Complexity: O(max_K)
 */

int main() {
    // Optimize standard I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int m;
    // Read the size of the arrays
    if (!(cin >> m)) return 0;

    // bitset to store existence of elements in the first array and the result intersection
    // Using 10001 to safely cover the range 0 < K < 10000
    bitset<10001> first_array_elements;
    bitset<10001> intersection_elements;

    // Read first array
    for (int i = 0; i < m; ++i) {
        int k;
        cin >> k;
        if (k >= 0 && k <= 10000) {
            first_array_elements.set(k);
        }
    }

    // Read second array and find intersection
    for (int i = 0; i < m; ++i) {
        int k;
        cin >> k;
        if (k >= 0 && k <= 10000 && first_array_elements.test(k)) {
            intersection_elements.set(k);
        }
    }

    // Print common elements in ascending order
    for (int i = 0; i <= 10000; ++i) {
        if (intersection_elements.test(i)) {
            cout << i << "\n";
        }
    }

    return 0;
}

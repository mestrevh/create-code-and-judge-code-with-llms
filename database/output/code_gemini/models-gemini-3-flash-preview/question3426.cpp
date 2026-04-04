/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>

using namespace std;

/**
 * Problem: Vetor de fatoriais
 * Task: Read a vector V of size n, compute vector W where W[i] = V[i]!
 * Time Complexity: O(n * max(V[i]))
 * Space Complexity: O(n)
 */

typedef unsigned long long ull;

int main() {
    // Optimize Standard I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;

    // Use vector to store input elements
    vector<int> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }

    // Print elements of V separated by space
    for (int i = 0; i < n; ++i) {
        cout << v[i] << " ";
    }
    cout << "\n";

    // Calculate and print factorials (W)
    // Using ull to handle values up to 20!
    for (int i = 0; i < n; ++i) {
        ull factorial = 1;
        for (int j = 2; j <= v[i]; ++j) {
            factorial *= j;
        }
        cout << factorial << " ";
    }
    cout << "\n";

    return 0;
}
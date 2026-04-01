/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * Problem: Intercâmbio (Exchange Students)
 * The goal is to determine if every student wanting to go from A to B
 * has a matching partner wanting to go from B to A.
 * 
 * Logic:
 * Let the input pairs be (S_i, D_i). 
 * For every (S_i, D_i), we need a matching (D_j, S_j) such that S_i = D_j and D_i = S_j.
 * This is equivalent to saying that the multiset of all (S_i, D_i) must be equal
 * to the multiset of all (D_i, S_i).
 * 
 * Complexity: O(N log N) per test case due to sorting.
 * Space: O(N) to store the pairs.
 */

int main() {
    // Standard competitive programming I/O optimization
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    while (cin >> n && n != 0) {
        // Optimization: If the number of candidates is odd, an exchange is impossible.
        if (n % 2 != 0) {
            int u, v;
            for (int i = 0; i < n; ++i) {
                cin >> u >> v;
            }
            cout << "NO\n";
            continue;
        }

        // We store the original pairs and the swapped destination pairs.
        // If the exchange is valid, the sorted version of both multisets must be identical.
        vector<pair<int, int>> original(n);
        vector<pair<int, int>> reversed(n);

        for (int i = 0; i < n; ++i) {
            cin >> original[i].first >> original[i].second;
            reversed[i].first = original[i].second;
            reversed[i].second = original[i].first;
        }

        sort(original.begin(), original.end());
        sort(reversed.begin(), reversed.end());

        // Vector comparison in C++ is O(N)
        if (original == reversed) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }

    return 0;
}
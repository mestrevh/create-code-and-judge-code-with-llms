/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>

using namespace std;

/**
 * Problem: Generate all subsets of {1, ..., n} in the specific lexicographical 
 * order shown in the test cases (Include-Exclude DFS order).
 * Constraints: 1 <= n <= 15.
 * Complexity: O(2^n) time and O(n) space.
 */

void generateSubsets(int current, int n, vector<int>& subset) {
    if (current > n) {
        cout << "{ ";
        for (int x : subset) {
            cout << x << " ";
        }
        cout << "}\n";
        return;
    }

    // Following the lexicographical order of bitmasks (Include then Exclude)
    // 1. Include the current element
    subset.push_back(current);
    generateSubsets(current + 1, n, subset);
    subset.pop_back();

    // 2. Exclude the current element
    generateSubsets(current + 1, n, subset);
}

int main() {
    // Fast I/O optimization
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (cin >> n) {
        vector<int> subset;
        subset.reserve(n);
        generateSubsets(1, n, subset);
    }

    return 0;
}
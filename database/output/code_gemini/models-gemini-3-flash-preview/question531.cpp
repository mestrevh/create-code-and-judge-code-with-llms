/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * Selection Sort Implementation
 * Time Complexity: O(N^2)
 * Space Complexity: O(N)
 * 
 * This program sorts an array using the Selection Sort algorithm and
 * prints the intermediate states as required.
 */

int main() {
    // Standard I/O optimization for Competitive Programming
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int val;
    vector<int> a;
    
    // Read all numbers from input
    while (cin >> val) {
        a.push_back(val);
    }

    int n = static_cast<int>(a.size());
    
    // Handle empty array case
    if (n == 0) {
        return 0;
    }

    // Selection Sort algorithm: iterate through the first n-1 elements
    for (int i = 0; i < n - 1; ++i) {
        int min_idx = i;
        
        // Find the index of the first occurrence of the minimum element in the unsorted part
        for (int j = i + 1; j < n; ++j) {
            if (a[j] < a[min_idx]) {
                min_idx = j;
            }
        }
        
        // Store the minimum value found in this step
        int min_val = a[min_idx];
        
        // Swap the current element with the found minimum element
        int temp = a[i];
        a[i] = a[min_idx];
        a[min_idx] = temp;

        // Output step details
        cout << "Menor elemento neste passo: " << min_val << "\n";
        cout << "Estado Atual: ";
        for (int k = 0; k < n; ++k) {
            cout << a[k] << (k == n - 1 ? "" : " | ");
        }
        // Blank line between steps as requested
        cout << "\n\n";
    }

    // Final result output
    cout << "Resultado Final: ";
    for (int k = 0; k < n; ++k) {
        cout << a[k] << (k == n - 1 ? "" : " | ");
    }
    cout << "\n";

    return 0;
}
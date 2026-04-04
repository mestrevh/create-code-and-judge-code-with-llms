/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

/**
 * Problem: Festa da Marilda 2
 * Goal: Read an initial list of guests, sort once, and then maintain the sorted order 
 * as small groups (up to 5) are added, without using the library's sort function again.
 * Complexity: Initial sort O(L log L), each group addition O(N) where N is current size.
 * Given total size is ~300, O(N) insertion is highly efficient.
 */

int main() {
    // Optimize standard I/O for faster execution
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<string> guests;
    string line;

    // Phase 1: Read initial guest list until "FIM"
    while (getline(cin, line)) {
        // Handle Windows-style carriage returns (\r) if present
        if (!line.empty() && line.back() == '\r') line.pop_back();
        if (line == "FIM") break;
        if (line.empty()) continue; // Skip unexpected empty lines
        guests.push_back(line);
    }

    // Restriction: Sort is only allowed once for the initial list
    if (!guests.empty()) {
        sort(guests.begin(), guests.end());
    }

    // Print initial sorted list
    for (int i = 0; i < (int)guests.size(); ++i) {
        cout << guests[i] << "\n";
    }

    // Phase 2: Add additional groups and maintain sorting manually
    int n;
    while (cin >> n && n != 0) {
        // Consume the remaining newline/spaces on the line with 'n'
        getline(cin, line);

        for (int i = 0; i < n; ++i) {
            if (!getline(cin, line)) break;
            if (!line.empty() && line.back() == '\r') line.pop_back();
            
            /** 
             * Maintain sorted order by finding the first element not less than 'line'.
             * lower_bound performs a binary search in O(log N).
             * vector::insert performs an O(N) move.
             */
            auto it = lower_bound(guests.begin(), guests.end(), line);
            guests.insert(it, line);
        }

        // Print separator before the updated list
        cout << "--------------------------------------------------\n";
        
        // Print updated list
        for (int i = 0; i < (int)guests.size(); ++i) {
            cout << guests[i] << "\n";
        }
    }

    return 0;
}

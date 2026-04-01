/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>

using namespace std;

/**
 * Standard backtracking function to generate balanced parentheses combinations.
 * n: Total pairs required.
 * openCount: Count of '(' used so far.
 * closeCount: Count of ')' used so far.
 * current: The string currently being built.
 * results: Storage for all valid combinations.
 */
void generateCombinations(int n, int openCount, int closeCount, string& current, vector<string>& results) {
    // Base case: if the current string has reached the length 2*N, it is complete.
    if (openCount == n && closeCount == n) {
        results.push_back(current);
        return;
    }

    // Add an opening parenthesis if we haven't reached the limit N.
    if (openCount < n) {
        current.push_back('(');
        generateCombinations(n, openCount + 1, closeCount, current, results);
        current.pop_back(); // Backtrack
    }

    // Add a closing parenthesis if it doesn't exceed the number of opening ones.
    if (closeCount < openCount) {
        current.push_back(')');
        generateCombinations(n, openCount, closeCount + 1, current, results);
        current.pop_back(); // Backtrack
    }
}

int main() {
    // Fast I/O optimization for Competitive Programming
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    // Read N from input
    if (!(cin >> n)) return 0;

    // Handle N=0 as per specific test case requirements
    if (n <= 0) {
        cout << "[]" << endl;
        return 0;
    }

    vector<string> results;
    string current = "";
    // Pre-allocate string memory for slight performance gain
    current.reserve(2 * n);
    
    // Generate all valid combinations
    generateCombinations(n, 0, 0, current, results);

    // Format output as [comb1,comb2,...]
    cout << "[";
    for (size_t i = 0; i < results.size(); ++i) {
        cout << results[i];
        if (i < results.size() - 1) {
            cout << ",";
        }
    }
    cout << "]" << endl;

    return 0;
}
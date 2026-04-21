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
 * Problem: Rotate a series of sentences 90 degrees clockwise.
 * The input sentences are transformed from a horizontal format (left-to-right, top-to-bottom)
 * to a vertical format (top-to-bottom, right-to-left).
 * 
 * Logic:
 * 1. Read all input strings until EOF.
 * 2. Find the maximum length (max_len) among all input strings.
 * 3. For each column index j from 0 to max_len - 1:
 *    a. Find the smallest index i in the original input such that lines[i] has a character at index j.
 *       This handles the "trailing spaces" rule: we only print characters for a given row j
 *       up to the last input string that actually reaches that length.
 *    b. Iterate from the last sentence (index N-1) down to the smallest index found (i).
 *    c. Print the character at index j if it exists, otherwise print a space for alignment.
 */

int main() {
    // Standard competitive programming I/O optimization
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<string> lines;
    string s;
    int max_len = 0;

    // Read until EOF
    while (getline(cin, s)) {
        // Handle potential carriage return characters from different OS line endings
        if (!s.empty() && s.back() == '\r') {
            s.pop_back();
        }
        lines.push_back(s);
        if ((int)s.length() > max_len) {
            max_len = (int)s.length();
        }
    }

    int N = (int)lines.size();
    if (N == 0) return 0;

    // Process each character position (the new "rows")
    for (int j = 0; j < max_len; ++j) {
        // Find the "boundary" for this row: the smallest original index i that has a character at j.
        // This ensures no unnecessary trailing spaces are printed.
        int last_original_index = -1;
        for (int i = 0; i < N; ++i) {
            if (j < (int)lines[i].length()) {
                last_original_index = i;
                break;
            }
        }

        // If no string has a character at index j, we're done (though max_len prevents this).
        if (last_original_index == -1) continue;

        // Print from the last input sentence towards the first (right-to-left requirement)
        for (int i = N - 1; i >= last_original_index; --i) {
            if (j < (int)lines[i].length()) {
                cout << lines[i][j];
            } else {
                // If this string is shorter than j, print a space to maintain alignment
                // with strings that exist at index j further down the column.
                cout << ' ';
            }
        }
        cout << '\n';
    }

    return 0;
}
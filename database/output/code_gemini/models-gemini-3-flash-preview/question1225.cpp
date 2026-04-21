/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <climits>
#include <cctype>

using namespace std;

/**
 * Problem: Find the maximum element in a given list of integers provided as a string like [1, 4, -9, 0, 6].
 * Complexity: O(N) where N is the length of the input string.
 * This solution parses the input character by character to handle brackets and commas.
 */

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long max_val = LLONG_MIN;
    bool found = false;
    string buffer = "";
    char c;

    // Standard competitive programming approach to read until EOF
    while (cin.get(c)) {
        if (isdigit(c) || c == '-') {
            buffer += c;
        } else {
            if (!buffer.empty() && buffer != "-") {
                try {
                    long long val = stoll(buffer);
                    if (!found || val > max_val) {
                        max_val = val;
                        found = true;
                    }
                } catch (...) {
                    // Silently ignore parsing errors if any
                }
                buffer = "";
            }
        }
    }

    // Process the final number if the string doesn't end with a non-digit character
    if (!buffer.empty() && buffer != "-") {
        try {
            long long val = stoll(buffer);
            if (!found || val > max_val) {
                max_val = val;
                found = true;
            }
        } catch (...) {
        }
    }

    if (found) {
        cout << max_val << endl;
    }

    return 0;
}
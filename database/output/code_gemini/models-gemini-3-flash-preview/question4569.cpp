/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>

using namespace std;

/**
 * Problem: Academia do Saulinho Bigode
 * Rules for valid names:
 * 1. Only letters (A-Z, a-z), spaces, or hyphens.
 * 2. Length between 3 and 30 characters.
 * 3. Starts and ends with a letter.
 * 4. No consecutive spaces or hyphens.
 * 5. Every word must start with an uppercase letter.
 */

int main() {
    // Fast I/O optimization
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    // Read the full input name
    if (!getline(cin, s)) {
        return 0;
    }

    // Clean up trailing characters like \r or \n that may come from different line ending formats
    while (!s.empty() && (s.back() == '\r' || s.back() == '\n')) {
        s.pop_back();
    }

    bool valid = true;
    int n = s.length();

    // Rule 2: Minimum 3 and maximum 30 characters
    if (n < 3 || n > 30) {
        valid = false;
    } else {
        // Lambda helpers for readability and speed
        auto is_letter = [](char c) {
            return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
        };
        auto is_upper = [](char c) {
            return (c >= 'A' && c <= 'Z');
        };
        auto is_symbol = [](char c) {
            return c == ' ' || c == '-';
        };

        // Rule 3: Must start and end with a letter
        if (!is_letter(s[0]) || !is_letter(s[n - 1])) {
            valid = false;
        } else {
            for (int i = 0; i < n; i++) {
                // Rule 1: Must contain only allowed characters
                if (!is_letter(s[i]) && !is_symbol(s[i])) {
                    valid = false;
                    break;
                }

                // Rule 4: No consecutive spaces or hyphens
                if (i < n - 1 && is_symbol(s[i]) && is_symbol(s[i + 1])) {
                    valid = false;
                    break;
                }

                // Rule 5: Every word (defined by starting at index 0 or after a space/hyphen) must be capitalized
                if (i == 0 || (i > 0 && is_symbol(s[i - 1]))) {
                    // Due to Rule 3 and Rule 4, s[i] must be a letter here
                    if (!is_upper(s[i])) {
                        valid = false;
                        break;
                    }
                }
            }
        }
    }

    // Output result in the format: NAME: 1 or NAME: 0
    cout << s << ": " << (valid ? 1 : 0) << endl;

    return 0;
}
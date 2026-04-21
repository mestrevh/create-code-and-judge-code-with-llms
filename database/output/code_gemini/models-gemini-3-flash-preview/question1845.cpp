/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>

using namespace std;

/**
 * Problem: Reverse a name and make the first and last characters uppercase, 
 * while the rest are lowercase.
 * Complexity: O(N), where N is the length of the name.
 */

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    // Read the entire line to allow for names with spaces
    if (!getline(cin, s)) {
        return 0;
    }

    // Remove potential trailing carriage returns (Windows/DOS compatibility)
    while (!s.empty() && (s.back() == '\r' || s.back() == '\n')) {
        s.pop_back();
    }

    // If string is empty after trimming, terminate
    if (s.empty()) {
        return 0;
    }

    // Reverse the string
    reverse(s.begin(), s.end());

    // Convert all characters to lowercase to handle cases like "TiAgo" -> "ogait"
    for (int i = 0; i < (int)s.size(); ++i) {
        s[i] = (char)tolower((unsigned char)s[i]);
    }

    // Make the first and last letters uppercase
    // Note: If length is 1, both s[0] and s[size-1] refer to the same character
    s[0] = (char)toupper((unsigned char)s[0]);
    s[s.size() - 1] = (char)toupper((unsigned char)s[s.size() - 1]);

    // Output the result
    cout << s << endl;

    return 0;
}
/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <vector>

using namespace std;

/**
 * Problem: Translation rules application.
 * Complexity: O(T * N * M * L) where T is test cases, N rules, M lines, L line length.
 * The rules are applied sequentially to each line of text.
 */

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    // Read n and m until both are zero
    while (cin >> n >> m && (n != 0 || m != 0)) {
        string dummy;
        getline(cin, dummy); // Consume the remaining newline in the buffer after reading n and m

        // Store replacement rules as pairs of (search_string, replacement_string)
        vector<pair<string, string>> rules(n);
        for (int i = 0; i < n; ++i) {
            string ruleLine;
            getline(cin, ruleLine);
            // Rules are in the format "STRING_A_SER_SUBSTITUIDA -> STRING_SUBSTITUTA"
            // We search for the " -> " delimiter which has exactly one space before and after.
            size_t pos = ruleLine.find(" -> ");
            if (pos != string::npos) {
                rules[i].first = ruleLine.substr(0, pos);
                rules[i].second = ruleLine.substr(pos + 4); // Skip " -> " (4 characters)
            } else {
                rules[i].first = "";
                rules[i].second = "";
            }
        }

        // Process each of the m lines of text
        for (int i = 0; i < m; ++i) {
            string textLine;
            getline(cin, textLine);
            
            // Apply each substitution rule in the order they were provided
            for (int j = 0; j < n; ++j) {
                if (rules[j].first.empty()) continue;
                
                size_t start_pos = 0;
                // Find all occurrences of the rule's key in the current state of the text line
                while ((start_pos = textLine.find(rules[j].first, start_pos)) != string::npos) {
                    textLine.replace(start_pos, rules[j].first.length(), rules[j].second);
                    // Increment the pointer by the length of the replacement to avoid infinite loops
                    // and to ensure we only replace occurrences in the string as it existed before this rule's pass.
                    start_pos += rules[j].second.length();
                }
            }
            // Output the corrected text line
            cout << textLine << "\n";
        }
    }

    return 0;
}
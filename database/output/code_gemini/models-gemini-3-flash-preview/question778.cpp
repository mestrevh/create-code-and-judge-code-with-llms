/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <list>

using namespace std;

int main() {
    // Optimize Standard I/O for faster processing
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string line;
    // Read input until EOF, processing each phrase (line)
    while (getline(cin, line)) {
        // Handle potential Windows-style line endings (\r\n)
        if (!line.empty() && line.back() == '\r') {
            line.pop_back();
        }

        // We use a list of strings to represent segments of the text.
        // Inserting at the beginning or end of a list is O(1).
        list<string> parts;
        auto it = parts.end();
        string current;
        // Optimization: reserve space for the current string segment
        current.reserve(line.size());

        for (char c : line) {
            if (c == '[') {
                // Home key: move cursor to the beginning
                if (!current.empty()) {
                    parts.insert(it, current);
                    current.clear();
                }
                it = parts.begin();
            } else if (c == ']') {
                // End key: move cursor to the end
                if (!current.empty()) {
                    parts.insert(it, current);
                    current.clear();
                }
                it = parts.end();
            } else {
                // Regular character: append to current buffer
                current += c;
            }
        }

        // Insert any remaining text in the buffer
        if (!current.empty()) {
            parts.insert(it, current);
        }

        // Print the reconstructed phrase
        for (const string& s : parts) {
            cout << s;
        }
        cout << "\n";
    }

    return 0;
}
/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <unordered_map>
#include <sstream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;

    unordered_map<string, string> dict;
    dict.reserve(n);

    string key, sep, val;
    for (int i = 0; i < n; ++i) {
        if (cin >> key >> sep >> val) {
            dict[key] = val;
        }
    }

    string line;
    getline(cin, line); // Consume newline from the last dictionary entry

    while (getline(cin, line)) {
        // Handle potential Windows-style line endings
        if (!line.empty() && line.back() == '\r') {
            line.pop_back();
        }
        
        // Stop condition
        if (line == "*") break;

        stringstream ss(line);
        string word;
        bool first = true;
        
        while (ss >> word) {
            if (!first) {
                cout << " ";
            }
            
            auto it = dict.find(word);
            if (it != dict.end()) {
                cout << it->second;
            } else {
                cout << word;
            }
            first = false;
        }
        cout << "\n";
    }

    return 0;
}
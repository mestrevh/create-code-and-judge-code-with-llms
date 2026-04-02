/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string line;
    string longest_word = "";
    int max_len = 0;

    while (getline(cin, line) && line != "0") {
        if (line.empty()) continue;

        stringstream ss(line);
        string word;
        vector<int> lengths;

        while (ss >> word) {
            int current_len = (int)word.length();
            lengths.push_back(current_len);
            if (current_len >= max_len) {
                max_len = current_len;
                longest_word = word;
            }
        }

        for (size_t i = 0; i < lengths.size(); ++i) {
            cout << lengths[i] << (i == lengths.size() - 1 ? "" : "-");
        }
        
        if (!lengths.empty()) {
            cout << "\n";
        }
    }

    if (max_len > 0) {
        cout << "Maior palavra: " << longest_word << "\n";
    }

    return 0;
}
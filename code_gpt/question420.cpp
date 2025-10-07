/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <sstream>

using namespace std;

bool decode(const vector<string>& enc_lines, const string& target, unordered_map<char, char>& mapping) {
    unordered_set<char> used;
    for (const auto& enc : enc_lines) {
        stringstream ss(enc);
        string word;
        for (char ch : target) {
            if (ch == ' ') {
                if (ss.peek() == ' ') ss.ignore();
                continue;
            }
            if (ss.eof()) return false;
            ss >> word;
            if (word.length() != 0) {
                if (!mapping.count(ch)) {
                    if (used.count(word[0])) return false;
                    mapping[ch] = word[0];
                    used.insert(word[0]);
                } else {
                    if (mapping[ch] != word[0]) return false;
                }
            }
        }
        if (!ss.eof()) return false;
    }
    return true;
}

void print_decoded(const vector<string>& enc_lines, int testCase) {
    string target = "the quick brown fox jumps over the lazy dog";
    unordered_map<char, char> mapping;
    bool found = decode(enc_lines, target, mapping);
    
    if (!found) {
        cout << "No solution.";
    } else {
        for (const auto& line : enc_lines) {
            string decoded = line;
            for (auto& ch : decoded) {
                if (ch != ' ') {
                    ch = mapping[ch];
                }
            }
            cout << decoded << endl;
        }
    }
    if (testCase > 0) cout << endl; // separate with a blank line
}

int main() {
    int n;
    cin >> n;
    cin.ignore();
    cin.ignore();

    for (int i = 0; i < n; ++i) {
        vector<string> enc_lines;
        string line;
        while (getline(cin, line) && !line.empty()) {
            enc_lines.push_back(line);
        }
        print_decoded(enc_lines, i);
    }
    return 0;
}

/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>

using namespace std;

bool canDecode(const string& cipher, const unordered_set<string>& dictionary, unordered_map<char, char>& mapping) {
    string decoded;
    for (char ch : cipher) {
        if (ch == ' ') {
            decoded += ' ';
        } else {
            decoded += mapping[ch];
        }
    }
    return dictionary.count(decoded);
}

bool backtrack(const vector<string>& ciphers, int index, unordered_map<char, char>& mapping, const unordered_set<string>& dictionary) {
    if (index == ciphers.size()) return true;

    string cipher = ciphers[index];
    for (const auto& word : dictionary) {
        if (word.size() != cipher.size()) continue;

        unordered_map<char, char> newMapping = mapping;
        unordered_set<char> usedMapped;

        bool valid = true;
        for (size_t i = 0; i < cipher.size(); ++i) {
            char c = cipher[i], w = word[i];
            if (newMapping.count(c)) {
                if (newMapping[c] != w) {
                    valid = false;
                    break;
                }
            } else {
                if (usedMapped.count(w)) {
                    valid = false;
                    break;
                }
                newMapping[c] = w;
                usedMapped.insert(w);
            }
        }

        if (valid && backtrack(ciphers, index + 1, newMapping, dictionary)) {
            return true;
        }
    }
    return false;
}

void decode(const vector<string>& ciphers, const unordered_set<string>& dictionary) {
    unordered_map<char, char> mapping;
    bool found = backtrack(ciphers, 0, mapping, dictionary);
    
    if (found) {
        for (const string& cipher : ciphers) {
            string decoded;
            for (char ch : cipher) {
                if (ch == ' ') {
                    decoded += ' ';
                } else {
                    decoded += mapping[ch];
                }
            }
            cout << decoded << endl;
        }
    } else {
        for (const string& cipher : ciphers) {
            string decoded(cipher.size(), '*');
            cout << decoded << endl;
        }
    }
}

int main() {
    int n;
    cin >> n;
    unordered_set<string> dictionary;
    string word;
    for (int i = 0; i < n; ++i) {
        cin >> word;
        dictionary.insert(word);
    }
    cin.ignore();
    
    vector<string> ciphers;
    string line;
    while (getline(cin, line)) {
        ciphers.push_back(line);
    }
    
    decode(ciphers, dictionary);
    return 0;
}

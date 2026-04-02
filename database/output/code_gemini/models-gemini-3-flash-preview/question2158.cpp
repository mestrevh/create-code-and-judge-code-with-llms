/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

string to_lower_str(string s) {
    string res = "";
    for (int i = 0; i < (int)s.length(); ++i) {
        unsigned char c = (unsigned char)s[i];
        if (c >= 'A' && c <= 'Z') {
            res += (char)(c + 32);
        } else if (c == 0xC3 && i + 1 < (int)s.length()) {
            unsigned char next = (unsigned char)s[i+1];
            if (next >= 0x80 && next <= 0x9E) {
                res += (char)0xC3;
                res += (char)(next + 0x20);
                i++;
            } else {
                res += (char)c;
            }
        } else if (c >= 0xC0 && c <= 0xDE && c != 0xD7) {
            res += (char)(c + 32);
        } else {
            res += (char)c;
        }
    }
    return res;
}

bool is_letter(unsigned char c) {
    if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) return true;
    if (c >= 128) return true;
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string line;
    if (!getline(cin, line)) return 0;

    vector<string> order;
    unordered_map<string, int> freq;
    unordered_map<string, bool> exists;

    string current = "";
    for (int i = 0; i <= (int)line.length(); ++i) {
        unsigned char c = (i < (int)line.length()) ? (unsigned char)line[i] : ' ';
        if (is_letter(c)) {
            current += (char)c;
        } else {
            if (!current.empty()) {
                string l = to_lower_str(current);
                if (!exists[l]) {
                    exists[l] = true;
                    order.push_back(l);
                }
                freq[l]++;
                current = "";
            }
        }
    }

    bool first = true;
    for (const string& w : order) {
        if (freq[w] > 1) {
            if (!first) cout << " ";
            cout << w;
            first = false;
        }
    }
    cout << endl;

    return 0;
}
/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string line;
    if (!getline(cin, line)) return 0;

    line = line + " ";

    vector<unsigned char> bytes(line.begin(), line.end());
    string current;

    unordered_set<string> seen;
    unordered_set<string> added;
    vector<string> result;

    auto flushWord = [&]() {
        if (!current.empty()) {
            string lower = current;
            for (char &ch : lower) {
                unsigned char c = static_cast<unsigned char>(ch);
                if (c >= 'A' && c <= 'Z') ch = static_cast<char>(c - 'A' + 'a');
            }
            if (seen.count(lower)) {
                if (!added.count(lower)) {
                    added.insert(lower);
                    result.push_back(lower);
                }
            } else {
                seen.insert(lower);
            }
            current.clear();
        }
    };

    for (size_t i = 0; i < bytes.size(); ) {
        unsigned char c = bytes[i];

        auto isAlphaByte = [&](unsigned char b) -> bool {
            if ((b >= 'A' && b <= 'Z') || (b >= 'a' && b <= 'z')) return true;
            if (b >= 0x80) return true;
            return false;
        };

        if (isAlphaByte(c)) {
            if (c < 0x80) {
                current.push_back(static_cast<char>(c));
                i++;
            } else {
                size_t len = 1;
                if ((c & 0xE0) == 0xC0) len = 2;
                else if ((c & 0xF0) == 0xE0) len = 3;
                else if ((c & 0xF8) == 0xF0) len = 4;

                string token;
                token.reserve(len);
                for (size_t k = 0; k < len && i + k < bytes.size(); k++) token.push_back(static_cast<char>(bytes[i + k]));
                current += token;
                i += len;
            }
        } else {
            flushWord();
            i++;
        }
    }

    for (size_t i = 0; i < result.size(); i++) {
        if (i) cout << ' ';
        cout << result[i];
    }
    return 0;
}
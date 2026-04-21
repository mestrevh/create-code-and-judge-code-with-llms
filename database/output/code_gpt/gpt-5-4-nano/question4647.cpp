/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string x;
    if (!(cin >> x)) return 0;

    string line, y;
    getline(cin, line);
    getline(cin, y);

    string s = y;
    string token;
    bool found = false;

    auto isWordChar = [](unsigned char c) {
        return isalnum(c) || c == '_';
    };

    string cur;
    for (size_t i = 0; i <= s.size(); i++) {
        unsigned char c = (i < s.size() ? (unsigned char)s[i] : (unsigned char)' ');
        if (isWordChar(c)) {
            cur.push_back((char)c);
        } else {
            if (!cur.empty()) {
                if (cur == x) {
                    found = true;
                    break;
                }
                cur.clear();
            }
        }
    }

    if (found) cout << "existe!";
    else cout << "nao existe";
    return 0;
}
/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    if (!getline(cin, s)) return 0;

    unordered_map<char, char> mp;
    mp['0'] = 'o';
    mp['1'] = 'l';
    mp['2'] = 'a';
    mp['3'] = 'e';
    mp['4'] = 's';
    mp['5'] = 'i';
    mp['6'] = 't';
    mp['7'] = 'b';
    mp['8'] = 'g';
    mp['9'] = 'p';

    string out;
    out.reserve(s.size());
    for (char c : s) {
        if (mp.count(c)) out.push_back(mp[c]);
        else out.push_back(c);
    }

    bool upperNext = true;
    for (size_t i = 0; i < out.size(); i++) {
        char &c = out[i];
        if (upperNext && c >= 'a' && c <= 'z') c = char(c - 'a' + 'A');
        if (c == '.') {
            upperNext = true;
        } else if (c == ' ' || c == '\t' || c == '\n' || c == '\r') {
        } else {
            upperNext = false;
        }
    }

    cout << out;
    return 0;
}
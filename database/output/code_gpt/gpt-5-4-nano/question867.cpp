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
    getline(cin, s);

    bool seen[26] = {false};
    for (unsigned char ch : s) {
        if (isalpha(ch)) {
            char c = tolower(ch);
            if (c >= 'a' && c <= 'z') seen[c - 'a'] = true;
        }
    }

    for (int i = 0; i < 26; i++) {
        if (seen[i]) cout << char('a' + i) << "\n";
    }
    return 0;
}
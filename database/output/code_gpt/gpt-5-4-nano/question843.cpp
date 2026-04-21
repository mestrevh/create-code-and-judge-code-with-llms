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

    int n = (int)s.size();
    int count = 0;
    bool inWord = false;

    for (int i = 0; i < n; i++) {
        unsigned char c = (unsigned char)s[i];
        bool isSpace = isspace(c);
        if (!isSpace && !inWord) {
            count++;
            inWord = true;
        } else if (isSpace) {
            inWord = false;
        }
    }

    cout << count << "\n";
    return 0;
}
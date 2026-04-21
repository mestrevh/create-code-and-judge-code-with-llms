/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    if (!(cin >> n)) return 0;
    while (n--) {
        string s;
        cin >> s;
        vector<char> mapping(256, 0);
        char nextChar = 'a';
        for (unsigned char ch : s) {
            if (mapping[ch] == 0) {
                mapping[ch] = nextChar;
                nextChar++;
            }
            cout << mapping[ch];
        }
        if (n) cout << "\n";
    }
    return 0;
}
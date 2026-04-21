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
    long long C;
    if (!getline(cin, s)) return 0;
    if (!(cin >> C)) return 0;

    C %= 26;
    if (C < 0) C += 26;

    for (char &ch : s) {
        if (ch >= 'A' && ch <= 'Z') {
            ch = char('A' + (ch - 'A' + C) % 26);
        } else if (ch >= 'a' && ch <= 'z') {
            char up = char(ch - 'a' + 'A');
            ch = char('A' + (up - 'A' + C) % 26);
        }
    }

    cout << s;
    return 0;
}
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
    long long K;
    if (!getline(cin, s)) return 0;
    if (!(cin >> K)) return 0;

    K %= 26;
    for (char &c : s) {
        if (c >= 'a' && c <= 'z') {
            c = char('a' + (c - 'a' + K) % 26);
        } else if (c >= 'A' && c <= 'Z') {
            c = char('a' + (tolower(c) - 'a' + K) % 26);
        } else {
            c = char(tolower((unsigned char)c));
        }
    }

    cout << s;
    return 0;
}
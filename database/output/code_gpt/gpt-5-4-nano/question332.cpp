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

    for (char &c : s) {
        if ('a' <= c && c <= 'z') c = char(c - 'a' + 'A');
    }

    cout << s << "\n";
    return 0;
}
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

    string aLine, bLine;
    if (!getline(cin, aLine)) return 0;
    if (!getline(cin, bLine)) return 0;

    char a = aLine.empty() ? '\0' : aLine[0];
    char b = bLine.empty() ? '\0' : bLine[0];

    for (char &c : s) {
        if (c == a) c = b;
    }

    cout << s << "\n";
    return 0;
}
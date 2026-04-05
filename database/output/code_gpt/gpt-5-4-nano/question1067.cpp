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

    string t;
    for (char c : s) if (!isspace((unsigned char)c)) t.push_back(c);

    if ((int)t.size() != 1) {
        cout << "1 caractere, por favor!";
        return 0;
    }

    char c = t[0];
    char lc = (char)tolower((unsigned char)c);

    if (lc == 'a' || lc == 'e' || lc == 'i' || lc == 'o' || lc == 'u')
        cout << "Eh vogal";
    else
        cout << "Nao eh vogal";

    return 0;
}
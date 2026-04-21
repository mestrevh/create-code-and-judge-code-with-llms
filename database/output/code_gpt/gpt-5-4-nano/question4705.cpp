/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

bool inverter_string2(const string& s) {
    string t;
    t.reserve(s.size());
    for (unsigned char c : s) {
        if (isalpha(c) || isdigit(c)) t.push_back((char)tolower(c));
    }
    int i = 0, j = (int)t.size() - 1;
    while (i < j) {
        if (t[i] != t[j]) return false;
        ++i; --j;
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s, line;
    if (!getline(cin, line)) return 0;
    s = line;

    bool ok = inverter_string2(s);
    if (ok) cout << "Eh um palindromo";
    else cout << "Nao eh um palindromo";
    return 0;
}
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
    while (true) {
        if (!getline(cin, s)) return 0;
        if (!s.empty() && (int)s.size() <= 20) break;
        cout << "Entrada invalida\n";
    }

    for (int i = 0; i < (int)s.size(); i++) {
        char c = s[i];
        if (c >= 'a' && c <= 'z') c = char(c - 'a' + 'A');
        for (int k = 0; k <= i; k++) cout << c;
        cout << "\n";
    }
    return 0;
}
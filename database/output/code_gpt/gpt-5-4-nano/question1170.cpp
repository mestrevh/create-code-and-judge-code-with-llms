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
    if (!(cin >> s)) return 0;

    if (s.size() != 10) {
        cout << "Codigo Invalido";
        return 0;
    }

    char c = s[6];
    if (c == 'b') cout << "Bulbassauro";
    else if (c == 'c') cout << "Charmander";
    else if (c == 's') cout << "Squirtle";
    else cout << "Codigo Invalido";

    return 0;
}
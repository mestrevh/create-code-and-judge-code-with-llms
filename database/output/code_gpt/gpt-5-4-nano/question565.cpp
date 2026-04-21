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

    if (s.empty() || (s.size() == 1 && (s[0] == '+' || s[0] == '-'))) {
        cout << "Entrada incorreta!";
        return 0;
    }

    size_t pos = 0;
    bool neg = false;
    if (s[0] == '+' || s[0] == '-') {
        neg = (s[0] == '-');
        pos = 1;
        if (pos == s.size()) {
            cout << "Entrada incorreta!";
            return 0;
        }
    }

    for (size_t i = pos; i < s.size(); i++) {
        if (!isdigit(static_cast<unsigned char>(s[i]))) {
            cout << "Entrada incorreta!";
            return 0;
        }
    }

    size_t digits = s.size() - pos;
    if (digits == 0 || digits > 5) {
        cout << "Entrada incorreta!";
        return 0;
    }

    cout << "O número possui " << digits << " algarismos!";
    return 0;
}
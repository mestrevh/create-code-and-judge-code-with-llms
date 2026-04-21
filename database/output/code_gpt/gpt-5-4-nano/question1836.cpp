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
    while (cin >> s) {
        if (s == "FIM") break;

        bool ok = true;
        long long value = 0;

        for (char c : s) {
            if (c >= '0' && c <= '9') {
                value = value * 10 + (c - '0');
            } else if (c == 'o' || c == 'O') {
                value = value * 10 + 0;
            } else if (c == 'l' || c == 'I') {
                value = value * 10 + 1;
            } else {
                ok = false;
                break;
            }
        }

        if (ok) cout << value << "\n";
        else cout << "ERRO\n";
    }

    return 0;
}
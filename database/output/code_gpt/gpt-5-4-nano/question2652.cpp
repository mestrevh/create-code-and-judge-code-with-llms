/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    char c;
    bool first = true;
    while (cin >> c) {
        if (!first) cout << "\n";
        first = false;

        for (char ch = 'A'; ch <= c; ch++) {
            if (ch != 'A') cout << ' ';
            cout << ch;
        }

        if (c == 'F') break;
    }
    return 0;
}
/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    char a, b;
    if (!(cin >> a)) return 0;
    cin >> b;

    int x = a - 'a';
    int y = b - 'a';
    if (x > y) swap(x, y);

    for (int i = x + 1; i <= y - 1; ++i) {
        if (i == (x + y) / 2) {
            cout << char('a' + i) << "\n";
            if ((x + y) % 2 == 1) {
                cout << char('a' + i + 1) << "\n";
            }
            break;
        }
    }

    return 0;
}
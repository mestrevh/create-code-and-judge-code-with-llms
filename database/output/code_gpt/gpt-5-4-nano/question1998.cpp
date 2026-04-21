/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int a, b;
    if (!(cin >> a)) return 0;
    while (a < 1 || a > 9) {
        cout << "Erro: valor invalido\n";
        if (!(cin >> a)) return 0;
    }

    if (!(cin >> b)) return 0;
    while (b < 1 || b > 9) {
        cout << "Erro: valor invalido\n";
        if (!(cin >> b)) return 0;
    }

    int start = min(a, b), end = max(a, b);
    for (int x = start; x <= end; x++) {
        for (int i = 1; i <= 9; i++) {
            cout << x << " x " << i << " = " << x * i;
            if (!(x == end && i == 9)) cout << "\n";
        }
        if (x != end) cout << "\n";
    }
    return 0;
}
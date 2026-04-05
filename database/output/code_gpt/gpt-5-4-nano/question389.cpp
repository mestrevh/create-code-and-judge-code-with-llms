/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    double a[6];
    for (int i = 0; i < 6; i++) {
        if (!(cin >> a[i])) return 0;
    }

    bool ok = true;
    for (int i = 1; i < 6; i++) {
        if (!(a[i] > a[i - 1])) {
            ok = false;
            break;
        }
    }

    cout << (ok ? "Ganha brinquedo" : "Sem brinquedo");
    return 0;
}
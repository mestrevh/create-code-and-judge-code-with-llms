/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    double x;
    while (true) {
        cout << "Informe uma nota entre 0 e 10:\n";
        if (!(cin >> x)) return 0;
        if (x >= 0 && x <= 10) {
            cout << "Valor valido\n";
            return 0;
        }
        cout << "Valor invalido\n";
    }
    return 0;
}
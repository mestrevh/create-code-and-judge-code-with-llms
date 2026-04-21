/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int x;
    for (int i = 1; i <= 5; i++) {
        cout << "Digite um numero inteiro:";
        if (!(cin >> x)) return 0;
        cout << "Numero " << i << ": " << x;
        if (i < 5) cout << "\n";
    }
    return 0;
}
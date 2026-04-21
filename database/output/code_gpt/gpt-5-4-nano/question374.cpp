/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long double salario;
    if (!(cin >> salario)) return 0;

    long double bonus = salario * 0.75L;

    cout << fixed << setprecision(2);

    if (bonus < 2000.0L) {
        cout << "ARGENTINA";
    } else if (bonus <= 3000.0L) {
        cout << "ESPANHA";
    } else {
        cout << "ALEMANHA";
    }
    return 0;
}
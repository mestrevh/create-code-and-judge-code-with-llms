/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    double massa, altura;
    if (!(cin >> massa >> altura)) return 0;

    double imc = massa / (altura * altura);
    cout << fixed << setprecision(2) << imc << "\n";
    return 0;
}
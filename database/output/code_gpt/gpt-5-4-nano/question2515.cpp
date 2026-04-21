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
    cout << "Digite a massa em Kg:";
    if (!(cin >> massa)) return 0;
    cout << "Digite a altura em m:";
    if (!(cin >> altura)) return 0;

    double imc = massa / (altura * altura);
    cout << "IMC = " << fixed << setprecision(1) << imc;
    return 0;
}
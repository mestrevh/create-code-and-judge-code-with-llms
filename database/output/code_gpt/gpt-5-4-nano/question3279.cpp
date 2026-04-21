/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    double peso, altura;
    if (!(cin >> peso)) return 0;
    cin >> altura;

    double imc = peso / (altura * altura);
    double imc2 = round(imc * 100.0) / 100.0;

    cout << fixed << setprecision(2) << imc2 << " ";
    if (imc2 < 18.0 || imc2 > 25.0) cout << "atencao";
    else cout << "normal";
    return 0;
}
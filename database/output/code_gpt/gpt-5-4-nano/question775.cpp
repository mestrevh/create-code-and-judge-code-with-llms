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
    if (!(cin >> massa)) return 0;
    if (!(cin >> altura)) return 0;

    double imc = massa / (altura * altura);

    string classificacao;
    if (imc < 18.5) classificacao = "MAGREZA";
    else if (imc <= 24.9) classificacao = "SAUDAVEL";
    else if (imc <= 29.9) classificacao = "SOBREPESO";
    else classificacao = "OBESIDADE";

    cout << fixed << setprecision(2) << imc << ' ' << classificacao;
    return 0;
}
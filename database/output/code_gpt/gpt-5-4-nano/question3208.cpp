/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    double altura, peso;
    if (!(cin >> altura >> peso)) return 0;

    double imc = peso / (altura * altura);
    double imcRound = round(imc * 100.0) / 100.0;

    cout << fixed << setprecision(2) << imcRound << "\n";

    string status;
    if (imcRound < 18.5) status = "Muito abaixo do peso";
    else if (imcRound < 20.0) status = "Abaixo do peso";
    else if (imcRound < 25.0) status = "Peso normal";
    else if (imcRound < 30.0) status = "Acima do peso";
    else if (imcRound < 35.0) status = "Obesidade grau I";
    else if (imcRound < 40.0) status = "Obesidade grau II";
    else status = "Obesidade grau III";

    cout << status;
    return 0;
}
/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    char bairro;
    double renda, consumo;
    if (!(cin >> bairro >> renda >> consumo)) return 0;

    if (renda < 0 || consumo < 0) {
        cout << "Renda e consumo nao podem ser negativos.";
        return 0;
    }

    string msgErro = "Bairro invalido.";
    if (bairro != 'S' && bairro != 'I' && bairro != 'T') {
        cout << msgErro;
        return 0;
    }

    double desconto = 0.0;

    if (bairro == 'S') {
        if (renda >= 0 && renda <= 16000 && consumo >= 0) desconto = 0.10;
    } else if (bairro == 'I') {
        if (renda >= 16001 && renda <= 26000 && consumo >= 0) desconto = 0.15;
    } else if (bairro == 'T') {
        if (renda >= 26001 && renda <= 36000 && consumo >= 0) desconto = 0.20;
    }

    double total = consumo * (1.0 - desconto);
    if (fabs(total - round(total)) < 1e-9) {
        cout << (long long)llround(total);
    } else {
        cout << fixed << setprecision(2) << total;
    }
    return 0;
}
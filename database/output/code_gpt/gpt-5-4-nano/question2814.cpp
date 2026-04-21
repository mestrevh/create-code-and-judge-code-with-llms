/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long dias, km;
    cout << "Digite a quantidade de dias de locacao:\n";
    if (!(cin >> dias)) return 0;
    cout << "Digite a quantidade de km rodados:\n";
    if (!(cin >> km)) return 0;

    if (dias < 0 || km < 0) {
        cout << "Valor Invalido / Valor total a ser pago em reais: n";
        return 0;
    }

    long long diaria = 90;
    long long cotaKmDia = 100;
    long long kmCota = dias * cotaKmDia;
    long long total;

    if (km <= kmCota) {
        total = dias * diaria;
    } else {
        total = dias * diaria + (km - kmCota) * 12;
    }

    cout << "Valor total a ser pago em reais: " << total;
    return 0;
}
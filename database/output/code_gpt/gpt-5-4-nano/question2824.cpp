/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int pessoas, cidade, quartos;
    if (!(cin >> pessoas)) return 0;
    if (!(cin >> cidade)) return 0;
    if (!(cin >> quartos)) return 0;

    double casa = 0.0;
    double barco = 0.0;
    double parque = 60.0 * pessoas;

    if (cidade == 1) {
        if (quartos == 2) casa = 600.0;
        else if (quartos == 3) casa = 900.0;
        barco = 75.0 * pessoas;
    } else if (cidade == 2) {
        if (quartos == 3) casa = 950.0;
        else if (quartos == 4) casa = 1120.0;
    }

    double total = casa + barco + parque;
    double porPessoa = total / pessoas;

    cout << fixed << setprecision(2);
    cout << "Digite a quantidade de pessoas:\n";
    cout << "Selecione a cidade escolhida: (1 - Pipa e 2 - Fortaleza)\n";
    cout << "Digite a quantidade de quartos:\n";
    cout << "Valor total da viagem: R$ " << total << "\n";
    cout << "Valor por pessoa: R$ " << porPessoa << "\n";

    return 0;
}
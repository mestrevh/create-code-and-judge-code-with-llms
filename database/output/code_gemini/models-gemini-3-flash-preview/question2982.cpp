/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    double N;
    if (!(cin >> N)) return 0;

    // Converte o valor para centavos (inteiro) para evitar erros de precisão de ponto flutuante.
    long long cents = (long long)round(N * 100.0);

    // Valores das notas em centavos: 100, 50, 20, 10, 5, 2.
    int note_values[] = {10000, 5000, 2000, 1000, 500, 200};
    for (int v : note_values) {
        long long qty = cents / v;
        if (qty > 0) {
            cout << qty << " nota(s) de R$ " << fixed << setprecision(2) << (double)v / 100.0 << "\n";
            cents %= v;
        }
    }

    // Valores das moedas em centavos: 1, 0.50, 0.25, 0.10, 0.05, 0.01.
    int coin_values[] = {100, 50, 25, 10, 5, 1};
    for (int v : coin_values) {
        long long qty = cents / v;
        if (qty > 0) {
            cout << qty << " moeda(s) de R$ " << fixed << setprecision(2) << (double)v / 100.0 << "\n";
            cents %= v;
        }
    }

    return 0;
}
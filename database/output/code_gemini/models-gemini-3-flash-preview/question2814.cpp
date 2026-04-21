/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <algorithm>

using namespace std;

/**
 * Problem: Rental Car Calculation
 * - Daily Rate: R$ 90
 * - KM Allowance: 100 KM/day
 * - Extra KM Rate: R$ 12/KM
 * - Input: days (int), km (int)
 * - Validation: negative values -> "Valor invalido"
 */

int main() {
    // Optimization for Competitive Programming
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long dias, km_rodados;

    // Prompt 1
    cout << "Digite a quantidade de dias de locacao:" << endl;
    if (!(cin >> dias)) return 0;

    // Prompt 2
    cout << "Digite a quantidade de km rodados:" << endl;
    if (!(cin >> km_rodados)) return 0;

    // Input Validation
    if (dias < 0 || km_rodados < 0) {
        cout << "Valor invalido" << endl;
    } else {
        // Daily rate calculation
        long long custo_fixo = dias * 90;
        
        // KM allowance calculation
        long long franquia_km = dias * 100;
        
        // Extra KM calculation
        long long km_excedente = 0;
        if (km_rodados > franquia_km) {
            km_excedente = km_rodados - franquia_km;
        }
        
        // Final calculation
        long long total = custo_fixo + (km_excedente * 12);
        
        // Output formatting
        cout << "Valor total a ser pago em reais: " << total << endl;
    }

    return 0;
}
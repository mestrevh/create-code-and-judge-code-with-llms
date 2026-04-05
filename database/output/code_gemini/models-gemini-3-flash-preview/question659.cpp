/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

/**
 * Problema: Vampiros
 * Solução: Problema clássico da Ruína do Apostador (Gambler's Ruin).
 * Vampire 1 (V1) começa com EV1 de energia e Vampire 2 (V2) com EV2.
 * A cada turno, V1 ganha D pontos com probabilidade p = AT/6, retirando de V2.
 * V2 ganha D pontos com probabilidade q = 1 - p, retirando de V1.
 * O jogo termina quando um deles chega a EV <= 0.
 * 
 * Isso equivale a uma caminhada aleatória com:
 * n1 = ceil(EV1 / D) unidades iniciais para V1.
 * n2 = ceil(EV2 / D) unidades iniciais para V2.
 * Probabilidade p de ganhar 1 unidade, q de perder 1 unidade.
 * Probabilidade de vitória de V1:
 * Se p = q = 0.5: n1 / (n1 + n2)
 * Se p != q: (1 - (q/p)^n1) / (1 - (q/p)^(n1 + n2))
 */

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int ev1, ev2, at, d;
    while (cin >> ev1 >> ev2 >> at >> d && (ev1 || ev2 || at || d)) {
        // Número de unidades (danos de valor D) que cada um pode suportar
        int n1 = (ev1 + d - 1) / d;
        int n2 = (ev2 + d - 1) / d;
        
        double prob_v1;

        if (at == 3) {
            // Caso p = q = 0.5 (3/6)
            prob_v1 = (double)n1 / (n1 + n2);
        } else {
            // Caso p != q
            double p = at / 6.0;
            double q = 1.0 - p;
            double r = q / p;
            
            // Fórmula da Ruína do Apostador: (1 - r^n1) / (1 - r^(n1+n2))
            prob_v1 = (1.0 - pow(r, n1)) / (1.0 - pow(r, n1 + n2));
        }

        // Impressão em percentagem com uma casa decimal
        cout << fixed << setprecision(1) << prob_v1 * 100.0 << "\n";
    }

    return 0;
}
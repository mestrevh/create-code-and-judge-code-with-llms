/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

void Calcula(double *concentracaoBase, double *concentracaoTotal, double *pOH, int indiceHidroxilas) {
    double base = *concentracaoBase;
    double total = *concentracaoTotal + (*concentracaoBase * indiceHidroxilas);
    *concentracaoTotal = total;
    if (total <= 0) {
        *pOH = numeric_limits<double>::infinity();
    } else {
        *pOH = -log10(total);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    double baseConc;
    while (cin >> baseConc) {
        if (baseConc == 0) break;
        string elem;
        int indice, indiceHidroxilas;
        string hidro;
        double ohMul;

        cin >> elem >> indice >> hidro >> indiceHidroxilas;

        double concentracaoBase = baseConc;
        double concentracaoTotal = 0.0;
        double pOH = 0.0;

        static double totalOH = 0.0;
        concentracaoTotal = totalOH;

        Calcula(&concentracaoBase, &concentracaoTotal, &pOH, indiceHidroxilas);

        totalOH = concentracaoTotal;

        double pH = 9.0 - pOH;
        cout.setf(std::ios::fixed);
        cout << setprecision(1) << pH << "\n";
    }
    return 0;
}
/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    double A, B, C;
    cout << "Digite o coeficiente A: ";
    if (!(cin >> A)) return 0;
    cout << "Digite o coeficiente B: ";
    cin >> B;
    cout << "Digite o coeficiente C: ";
    cin >> C;

    double delta = B * B - 4.0 * A * C;

    if (delta < 0) {
        cout << "A funcao nao tem raizes reais";
    } else if (delta == 0) {
        double x = -B / (2.0 * A);
        cout << "Primeira raiz: " << fixed << setprecision(6) << x << "\n";
        cout << "Segunda raiz: " << fixed << setprecision(6) << x;
    } else {
        double sqrtDelta = sqrt(delta);
        double x1 = (-B + sqrtDelta) / (2.0 * A);
        double x2 = (-B - sqrtDelta) / (2.0 * A);
        cout << "Primeira raiz: " << fixed << setprecision(6) << x1 << "\n";
        cout << "Segunda raiz: " << fixed << setprecision(6) << x2;
    }

    return 0;
}
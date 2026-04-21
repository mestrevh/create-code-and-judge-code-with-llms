/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long double A, B, C;
    cout << "Digite o coeficiente A: ";
    if (!(cin >> A)) return 0;
    cout << "Digite o coeficiente B: ";
    cin >> B;
    cout << "Digite o coeficiente C: ";
    cin >> C;

    long double delta = B * B - 4 * A * C;

    if (delta < 0) {
        cout << "A funcao nao tem raizes reais";
        return 0;
    }

    if (fabsl(A) < 1e-18) {
        if (fabsl(B) < 1e-18) {
            if (fabsl(C) < 1e-18) {
                cout << "A funcao nao tem raizes reais";
            } else {
                cout << "A funcao nao tem raizes reais";
            }
        } else {
            long double x = -C / B;
            cout << "Primeira raiz: " << (double)x << "\n";
            cout << "Segunda raiz: " << (double)x;
        }
        return 0;
    }

    long double sqrtDelta = sqrt((double)delta);
    long double x1 = (-B + sqrtDelta) / (2 * A);
    long double x2 = (-B - sqrtDelta) / (2 * A);

    cout << "Primeira raiz: " << (double)x1 << "\n";
    cout << "Segunda raiz: " << (double)x2;

    return 0;
}
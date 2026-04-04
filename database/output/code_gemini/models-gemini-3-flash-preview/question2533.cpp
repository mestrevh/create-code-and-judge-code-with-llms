/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <cmath>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    double A, B, C;
    while (cin >> A >> B >> C) {
        cout << "Digite o coeficiente A:" << "\n";
        cout << "Digite o coeficiente B:" << "\n";
        cout << "Digite o coeficiente C:" << "\n";

        double delta = (B * B) - (4.0 * A * C);

        if (delta < 0) {
            cout << "A funcao nao tem raizes reais" << "\n";
        } else {
            double sqrtDelta = sqrt(delta);
            double r1 = (-B + sqrtDelta) / (2.0 * A);
            double r2 = (-B - sqrtDelta) / (2.0 * A);
            
            cout << "Primeira raiz: " << r1 << "\n";
            cout << "Segunda raiz: " << r2 << "\n";
        }
    }

    return 0;
}
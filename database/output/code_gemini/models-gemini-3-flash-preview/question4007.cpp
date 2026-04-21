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

    double a, b, c;
    while (cin >> a >> b >> c) {
        cout << "Digite o coeficiente A:" << "\n";
        cout << "Digite o coeficiente B:" << "\n";
        cout << "Digite o coeficiente C:" << "\n";

        double delta = (b * b) - (4.0 * a * c);

        if (delta < 0) {
            cout << "A funcao nao tem raizes reais" << "\n";
        } else {
            double sqrtDelta = sqrt(delta);
            double r1 = (-b + sqrtDelta) / (2.0 * a);
            double r2 = (-b - sqrtDelta) / (2.0 * a);

            cout << fixed << setprecision(6);
            cout << "Primeira raiz: " << r1 << "\n";
            cout << "Segunda raiz: " << r2 << "\n";
        }
    }

    return 0;
}
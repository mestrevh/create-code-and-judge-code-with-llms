/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main() {
    double A, B, C;
    cout << "Digite o coeficiente A:\n";
    cin >> A;
    cout << "Digite o coeficiente B:\n";
    cin >> B;
    cout << "Digite o coeficiente C:\n";
    cin >> C;

    double delta = B * B - 4 * A * C;

    if (delta < 0) {
        cout << "A funcao nao tem raizes reais\n";
    } else {
        double r1 = (-B + sqrt(delta)) / (2 * A);
        double r2 = (-B - sqrt(delta)) / (2 * A);
        cout << fixed << setprecision(6);
        cout << "Primeira raiz: " << r1 << "\n";
        cout << "Segunda raiz: " << r2 << "\n";
    }
    return 0;
}

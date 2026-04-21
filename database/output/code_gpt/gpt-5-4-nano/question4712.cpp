/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    double A, B;
    if (!(cin >> A)) return 0;
    if (!(cin >> B)) return 0;

    double C = A + B;
    double D = B - A;
    double E = A * B;

    cout << fixed << setprecision(1) << A << ".0 + " << B << ".0 = " << C << ".0\n";
    cout << fixed << setprecision(1) << B << ".0 - " << A << ".0 = " << D << ".0\n";
    cout << fixed << setprecision(1) << A << ".0 * " << B << ".0 = " << E << ".0\n";

    if (A == 0.0) {
        cout << "B / A = Indeterminado";
    } else {
        double F = B / A;
        cout << fixed << setprecision(16) << B << ".0 / " << A << ".0 = " << F;
    }

    return 0;
}
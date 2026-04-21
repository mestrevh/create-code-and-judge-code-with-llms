/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    double a, b, c;
    if (!(cin >> a)) return 0;
    cin >> b >> c;

    if (a == 0.0) {
        cout << "Se a = 0, nao temos uma equacao do segundo grau.";
        return 0;
    }

    double delta = b * b - 4 * a * c;

    cout << fixed << setprecision(2);
    cout << "Para os seguintes coeficientes: " << a << ", " << b << " e " << c << ". O delta eh: " << delta << "\n";

    const double eps = 1e-9;

    if (delta > eps) {
        double sqrtDelta = sqrt(delta);
        double x1 = (-b - sqrtDelta) / (2.0 * a);
        double x2 = (-b + sqrtDelta) / (2.0 * a);
        cout << "A equacao possui duas raizes reais distintas.\n";
        cout << "As raizes sao: Raiz 1 e Raiz 2\n";
        cout << x1 << " e " << x2;
    } else if (delta < -eps) {
        cout << "A equacao nao possui raizes reais.";
    } else {
        double x = (-b) / (2.0 * a);
        cout << "A equacao possui duas raizes reais iguais.\n";
        cout << "As raizes sao: " << x << " e " << x;
    }

    return 0;
}
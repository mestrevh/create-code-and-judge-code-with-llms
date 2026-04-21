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
    if (!(cin >> a >> b >> c)) return 0;

    if (a == 0) {
        cout << "Se a = 0, nao temos uma equacao do segundo grau." << endl;
    } else {
        double delta = b * b - 4.0 * a * c;
        // Small adjustment to avoid -0.00 display
        if (abs(delta) < 1e-9) delta = 0.0;

        cout << "Para os seguintes coeficientes: " << a << ", " << b << " e " << c << ". O delta eh: ";
        cout << fixed << setprecision(2) << delta << endl;

        if (delta > 1e-9) {
            cout << "A equacao possui duas raizes reais distintas." << endl;
            double r1 = (-b + sqrt(delta)) / (2.0 * a);
            double r2 = (-b - sqrt(delta)) / (2.0 * a);
            if (abs(r1) < 1e-9) r1 = 0.0;
            if (abs(r2) < 1e-9) r2 = 0.0;
            cout << "As raizes sao: " << fixed << setprecision(2) << r1 << " e " << r2 << endl;
        } else if (delta < -1e-9) {
            cout << "A equacao nao possui raizes reais." << endl;
        } else {
            cout << "A equacao possui duas raizes reais iguais." << endl;
            double r = -b / (2.0 * a);
            if (abs(r) < 1e-9) r = 0.0;
            cout << "As raizes sao: " << fixed << setprecision(2) << r << " e " << r << endl;
        }
    }

    return 0;
}
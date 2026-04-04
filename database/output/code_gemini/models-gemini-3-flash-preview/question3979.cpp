/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>

using namespace std;

double calcularQ1(double rendimento, double trabalhoJoule) {
    // R = (t / Q1) * 100 => Q1 = (t * 100) / R
    // Conversão para caloria: 1 cal = 4 J => cal = Joule / 4
    double q1Joule = (trabalhoJoule * 100.0) / rendimento;
    return q1Joule / 4.0;
}

double calcularQ2(double q1Caloria, double trabalhoJoule) {
    // Q1 = t + Q2 => Q2 = Q1 - t
    double trabalhoCaloria = trabalhoJoule / 4.0;
    return q1Caloria - trabalhoCaloria;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    double R, t;
    while (cin >> R && R < 100.0) {
        if (!(cin >> t)) break;

        double q1 = calcularQ1(R, t);
        double q2 = calcularQ2(q1, t);

        cout << fixed << setprecision(2);
        cout << "Q1 = " << q1 << " cal" << "\n";
        cout << "Q2 = " << q2 << " cal" << "\n";
    }

    return 0;
}
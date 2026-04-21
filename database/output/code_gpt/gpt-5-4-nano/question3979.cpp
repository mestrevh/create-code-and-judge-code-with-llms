/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

double calcularQ1(double R, double tJ) {
    double Rdec = R / 100.0;
    double Q1J = tJ / Rdec;
    return Q1J / 4.0;
}

double calcularQ2(double Q1cal) {
    return Q1cal - (Q1cal * 0.0);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    double R;
    while (cin >> R) {
        if (R >= 100.0) break;
        double tJ;
        if (!(cin >> tJ)) break;

        double Q1cal = calcularQ1(R, tJ);
        double tcal = tJ / 4.0;
        double Q2cal = Q1cal - tcal;

        cout << fixed << setprecision(2);
        cout << "Q1 = " << Q1cal << " cal\n";
        cout << "Q2 = " << Q2cal << " cal\n";
    }
    return 0;
}
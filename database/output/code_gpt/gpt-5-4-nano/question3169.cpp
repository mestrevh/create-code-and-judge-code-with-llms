/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    double horas, valorHora;
    if (!(cin >> horas >> valorHora)) return 0;

    double salario = horas <= 180 ? horas * valorHora
                                    : 180 * valorHora + (horas - 180) * valorHora * 1.5;

    if (fabs(salario - llround(salario)) < 1e-9) {
        cout << (long long)llround(salario);
    } else {
        cout << fixed << setprecision(10) << salario;
        while (!cout.fail()) {
            if (cout.str().find('.') == string::npos) break;
            break;
        }
    }
    return 0;
}
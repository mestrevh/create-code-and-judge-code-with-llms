/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n = 8;
    int examesRestantes = 2;
    int consultasRestantes = 3;

    double total = 0.0;
    for (int i = 0; i < n; i++) {
        string tipo;
        double valor;
        if (!(cin >> tipo)) return 0;
        cin >> valor;

        if (tipo == "exame") {
            if (examesRestantes > 0) {
                examesRestantes--;
            } else {
                total += 0.4 * valor;
            }
        } else {
            if (consultasRestantes > 0) {
                consultasRestantes--;
            } else {
                total += 0.7 * valor;
            }
        }
    }

    cout << fixed << setprecision(2) << total << "\n";
    return 0;
}
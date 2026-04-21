/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    for (int i = 0; i < 3; i++) {
        long long x, y;
        long long K;
        if (!(cin >> x >> y >> K)) return 0;

        long double IAF = (long double)x * (long double)y;
        IAF = fabsl(IAF);

        cout << "O aluno de índice " << K << " possui o valor IAF igual a "
             << fixed << setprecision(2) << (double)IAF << " e a descrição de ";

        if (IAF < 1e-9) {
            cout << "Calouro.";
        } else if (IAF < 100.0L) {
            cout << "Morador do Grad.";
        } else if (IAF < 500.0L) {
            cout << "Conserta Impressoras.";
        } else {
            cout << "Sem volta.";
        }

        if (i < 2) cout << "\n";
    }

    return 0;
}
/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    double C, i;
    int X;
    if (!(cin >> C >> i >> X)) return 0;

    int trimestres = X * 4;
    double montante = C;

    cout << fixed << setprecision(2);
    for (int t = 1; t <= trimestres; ++t) {
        double rendimento = montante * i;
        montante += rendimento;
        cout << "Rendimento: " << rendimento << " Montante: " << montante << "\n";
    }
    return 0;
}
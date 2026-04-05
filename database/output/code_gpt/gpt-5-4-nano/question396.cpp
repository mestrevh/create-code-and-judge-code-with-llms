/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    const double multaPorVeiculoExtra = 12.89;
    double total = 0.0;
    int casasMultadas = 0;

    int v;
    while (cin >> v) {
        if (v == 999) break;
        if (v > 2) {
            casasMultadas++;
            total += (v - 2) * multaPorVeiculoExtra;
        }
    }

    cout << fixed << setprecision(2) << total << "\n" << casasMultadas << "\n";
    return 0;
}
/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    double peso;
    if (!(cin >> peso)) return 0;

    double taxa = 0.0;
    bool excedido = false;

    if (peso <= 20.0) {
        taxa = 0.0;
    } else if (peso <= 25.0) {
        taxa = (peso - 20.0) * 12.5;
    } else if (peso <= 30.0) {
        taxa = (peso - 25.0) * 32.75 + 5.0 * 12.5;
    } else {
        excedido = true;
    }

    cout.setf(std::ios::fixed);
    cout << setprecision(2);

    if (excedido) {
        cout << "PESO LIMITE EXCEDIDO";
    } else {
        double rounded = std::round(taxa * 100.0) / 100.0;
        cout << rounded;
    }

    return 0;
}
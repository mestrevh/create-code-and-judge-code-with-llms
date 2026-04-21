/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    char sexo;
    double h;
    if (!(cin >> sexo)) return 0;
    if (!(cin >> h)) return 0;

    if (h <= 0) {
        cout << "Altura invalida.";
        return 0;
    }

    double peso;
    if (sexo == 'm') {
        peso = (72.7 * h) - 58.0;
    } else if (sexo == 'f') {
        peso = (62.1 * h) - 44.7;
    } else {
        cout << "O sexo informado eh invalido.";
        return 0;
    }

    cout.setf(std::ios::fixed);
    cout << setprecision(2) << peso;
    return 0;
}
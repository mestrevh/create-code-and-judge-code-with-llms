/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cout << "Digite o sexo: (0 - M e 1 - F)\n";
    double sexo;
    if (!(cin >> sexo)) return 0;

    cout << "Digite a altura em metros:\n";
    double h;
    if (!(cin >> h)) return 0;

    if (h <= 0) {
        cout << "Altura invalida";
        return 0;
    }

    if (!(sexo == 0 || sexo == 1)) {
        cout << "O sexo informado e invalido.";
        return 0;
    }

    double peso = (sexo == 0) ? (72.7 * h - 58.0) : (62.1 * h - 44.7);
    cout << "Peso ideal: " << fixed << setprecision(1) << peso << " kg";
    return 0;
}
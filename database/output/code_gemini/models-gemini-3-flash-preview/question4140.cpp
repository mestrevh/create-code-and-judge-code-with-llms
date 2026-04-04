/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    char tipo, operacao;
    if (!(cin >> tipo)) return 0;

    if (tipo != 'c' && tipo != 'e') {
        cout << "Entrada invalida! Voce deve usar 'c' (cilindro) ou 'e' (esfera)." << endl;
        return 0;
    }

    if (!(cin >> operacao)) return 0;

    if (operacao != 'a' && operacao != 'v') {
        cout << "Entrada invalida! Entre com 'a' (area) ou 'v' (volume)." << endl;
        return 0;
    }

    const double pi = 3.1415;
    cout << fixed << setprecision(2);

    if (tipo == 'e') {
        double r;
        if (!(cin >> r)) return 0;
        if (operacao == 'a') {
            cout << "A area da esfera de raio " << r << " eh:" << endl;
            cout << (4.0 * pi * r * r) << endl;
        } else {
            cout << "O volume da esfera de raio " << r << " eh:" << endl;
            cout << (4.0 / 3.0 * pi * r * r * r) << endl;
        }
    } else {
        double r, h;
        if (!(cin >> r >> h)) return 0;
        if (operacao == 'a') {
            cout << "A area do cilindro de raio " << r << " e altura " << h << " eh:" << endl;
            cout << (2.0 * pi * r * (r + h)) << endl;
        } else {
            cout << "O volume do cilindro de raio " << r << " e altura " << h << " eh:" << endl;
            cout << (pi * r * r * h) << endl;
        }
    }

    return 0;
}
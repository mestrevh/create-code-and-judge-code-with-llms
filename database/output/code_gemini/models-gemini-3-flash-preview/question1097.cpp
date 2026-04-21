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

    char sexo;
    double h;

    if (!(cin >> sexo >> h)) {
        return 0;
    }

    if (sexo != 'm' && sexo != 'f') {
        cout << "O sexo informado eh invalido." << endl;
    } else if (h <= 0) {
        cout << "Altura invalida." << endl;
    } else {
        double peso_ideal;
        if (sexo == 'm') {
            peso_ideal = (72.7 * h) - 58.0;
        } else {
            peso_ideal = (62.1 * h) - 44.7;
        }
        cout << fixed << setprecision(2) << peso_ideal << endl;
    }

    return 0;
}
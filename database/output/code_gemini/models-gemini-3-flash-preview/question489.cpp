/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    double totalClara = 0.0;
    double totalDiana = 0.0;
    double valor;
    string nome;

    for (int i = 0; i < 6; ++i) {
        if (!(cin >> valor >> nome)) break;
        if (nome == "Clara" || nome == "CLARA" || nome == "clara") {
            totalClara += valor;
        } else {
            totalDiana += valor;
        }
    }

    if (abs(totalClara - totalDiana) < 1e-9) {
        cout << "MORADORAS QUITES" << endl;
    } else if (totalClara > totalDiana) {
        double divida = (totalClara - totalDiana) / 2.0;
        cout << "DIANA " << fixed << setprecision(2) << divida << endl;
    } else {
        double divida = (totalDiana - totalClara) / 2.0;
        cout << "CLARA " << fixed << setprecision(2) << divida << endl;
    }

    return 0;
}
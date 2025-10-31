/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int main() {
    double total = 0.0, clara = 0.0, diana = 0.0;
    const int contas = 6;

    for (int i = 0; i < contas; ++i) {
        double valor;
        string nome;
        cin >> valor >> nome;
        total += valor;
        if (nome == "Clara") clara += valor;
        else if (nome == "Diana") diana += valor;
    }

    double media = total / 2.0;
    clara -= media;
    diana -= media;

    if (clara > 0) {
        cout << "DIANA\n" << fixed << setprecision(2) << clara << endl;
    } else if (diana > 0) {
        cout << "CLARA\n" << fixed << setprecision(2) << diana << endl;
    } else {
        cout << "MORADORAS QUITES\n";
    }

    return 0;
}

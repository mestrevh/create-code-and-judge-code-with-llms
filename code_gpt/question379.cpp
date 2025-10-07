/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
using namespace std;

int main() {
    double distancias[7];
    int diasCumpridos = 0;

    for (int i = 0; i < 7; i++) {
        cin >> distancias[i];
        if (distancias[i] >= 8.0) {
            diasCumpridos++;
        }
    }

    if (diasCumpridos >= 5) {
        cout << "Desempenho otimo" << endl;
    } else if (diasCumpridos >= 3) {
        cout << "Desempenho razoavel" << endl;
    } else {
        cout << "Desempenho ruim" << endl;
    }

    return 0;
}

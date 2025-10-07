/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
using namespace std;

int main() {
    double valor;
    int quantidade;
    int totalTrocados = 0;
    double totalValor = 0;

    for (int i = 0; i < 6; ++i) {
        cin >> valor >> quantidade;
        if (quantidade > 1) {
            totalTrocados += (quantidade - 1);
            totalValor += valor * (quantidade - 1);
        }
    }

    cout << totalTrocados << endl;
    if (totalValor >= 800) {
        cout << "SIM" << endl;
    } else {
        cout << "NAO" << endl;
    }

    return 0;
}

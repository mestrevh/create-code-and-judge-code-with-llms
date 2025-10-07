/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
using namespace std;

int main() {
    int X, D, T, Y;
    cin >> X;
    int totalDano = 0, tempoTotal = 0;

    for (int i = 0; i < X; i++) {
        cin >> D >> T;
        totalDano += D;
        tempoTotal = max(tempoTotal, T);
    }

    cin >> Y;
    int recuperacao = Y * tempoTotal;
    int vidaRestante = 100 + recuperacao - totalDano;

    if (vidaRestante > 0) {
        cout << "Inimigo Vivo" << endl;
    } else {
        cout << "Inimigo Morto" << endl;
    }

    return 0;
}

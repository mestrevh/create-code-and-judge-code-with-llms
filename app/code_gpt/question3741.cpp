/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>

using namespace std;

void ajudearachel(float troco) {
    int notas[5] = {50, 20, 10, 5, 2};
    float moedas[5] = {1.0, 0.50, 0.25, 0.10, 0.05};
    int numNotas = 0, numMoedas = 0;

    for (int i = 0; i < 5; i++) {
        while (troco >= notas[i]) {
            troco -= notas[i];
            numNotas++;
        }
    }

    for (int i = 0; i < 5; i++) {
        while (troco >= moedas[i]) {
            troco -= moedas[i];
            numMoedas++;
        }
    }

    cout << fixed << setprecision(2) << troco + numNotas * notas[0] + numMoedas * moedas[0] << endl;
    cout << numNotas << " notas e " << numMoedas << " moedas" << endl;
}

int main() {
    float pedido, pago;
    cin >> pedido >> pago;

    float troco = pago - pedido;

    ajudearachel(troco);
    
    return 0;
}

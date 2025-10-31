/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
using namespace std;

int main() {
    int dias, km;
    cout << "Digite a quantidade de dias de locacao:" << endl;
    cin >> dias;
    cout << "Digite a quantidade de km rodados:" << endl;
    cin >> km;

    if (dias < 0 || km < 0) {
        cout << "Valor invalido" << endl;
    } else {
        int valorTotal = dias * 90;
        if (km > dias * 100) {
            valorTotal += (km - dias * 100) * 12;
        }
        cout << "Valor total a ser pago em reais: " << valorTotal << endl;
    }

    return 0;
}

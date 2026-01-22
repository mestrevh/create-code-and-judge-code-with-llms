/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
using namespace std;

int main() {
    int consumo;
    cout << "Digite o consumo de agua em m3:" << endl;
    cin >> consumo;

    if (consumo < 0) {
        cout << "Numeros negativos nao sao aceitos." << endl;
        return 0;
    }

    int valor = 7; // Assinatura básica

    if (consumo > 10) {
        if (consumo <= 30) {
            valor += (consumo - 10) * 1; // 11 a 30
        } else if (consumo <= 100) {
            valor += 20 + (consumo - 30) * 2; // 31 a 100
        } else {
            valor += 20 + 140 + (consumo - 100) * 3; // Acima de 100
        }
    }

    cout << "O valor a ser pago e de R$ " << valor << "." << endl;
    return 0;
}

/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>

using namespace std;

double CalculaMulta(int velocidade) {
    const int limite = 50;
    double multa = 0.0;

    if (velocidade > limite) {
        double excesso = velocidade - limite;

        if (excesso <= limite * 0.1) {
            multa = 230.00;
        } else if (excesso <= limite * 0.2) {
            multa = 340.00;
        } else {
            multa = 19.28 * excesso;
        }
    }

    return multa;
}

int main() {
    int velocidade;
    cin >> velocidade;

    double resultado = CalculaMulta(velocidade);
    cout << fixed << setprecision(2) << resultado << endl;

    return 0;
}

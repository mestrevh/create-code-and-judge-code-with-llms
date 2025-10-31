/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    double velocidadeMaxima, velocidadeVeiculo;
    cin >> velocidadeMaxima >> velocidadeVeiculo;

    double multa = 0.0;
    int pontos = 0;

    if (velocidadeVeiculo <= velocidadeMaxima) {
        multa = 0.0;
        pontos = 0;
    } else if (velocidadeVeiculo <= velocidadeMaxima * 1.2) {
        multa = 85.13;
        pontos = 4;
    } else if (velocidadeVeiculo <= velocidadeMaxima * 1.5) {
        multa = 127.69;
        pontos = 5;
    } else {
        multa = 574.62;
        pontos = 7;
    }

    cout << fixed << setprecision(2) << multa << endl;
    cout << pontos << endl;

    return 0;
}

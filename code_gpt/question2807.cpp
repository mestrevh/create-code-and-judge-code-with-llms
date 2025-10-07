/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    int dias;
    int km;
    const double diaria = 30.0;
    const double precoPorKm = 0.01;
    const double desconto = 0.10;

    cout << "Digite a quantidade de dias de locacao:" << endl;
    cin >> dias;
    cout << "Digite a quantidade de km rodados:" << endl;
    cin >> km;

    double valorTotal = (dias * diaria) + (km * precoPorKm);
    valorTotal *= (1 - desconto);

    cout << fixed << setprecision(6);
    cout << "Valor a pagar pelo aluguel: R$ " << valorTotal << endl;

    return 0;
}

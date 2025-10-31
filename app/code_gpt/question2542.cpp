/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    double reais;
    const double dolar = 3.87, euro = 4.35;

    while (cin >> reais) {
        cout << "Digite o valor em reais:\n";
        cout << fixed << setprecision(4);
        cout << "Valor convertido em dolar: " << reais / dolar << endl;
        cout << "Valor convertido em euro: " << reais / euro << endl;
    }
    return 0;
}

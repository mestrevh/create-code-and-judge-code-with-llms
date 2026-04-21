/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    double reais;
    while (cin >> reais) {
        double dolar = reais / 3.87;
        double euro = reais / 4.35;

        cout << "Digite o valor em reais:" << "\n";
        cout << "Valor convertido em dolar: " << fixed << setprecision(2) << dolar << "\n";
        cout << "Valor convertido em euro: " << fixed << setprecision(2) << euro << "\n";
    }

    return 0;
}
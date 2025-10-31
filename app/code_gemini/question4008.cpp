/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>

int main() {
    using namespace std;

    double reais;

    cout << "Digite o valor em reais:" << endl;
    cin >> reais;

    const double taxa_dolar = 3.87;
    const double taxa_euro = 4.35;

    double valor_dolar = reais / taxa_dolar;
    double valor_euro = reais / taxa_euro;

    cout << fixed << setprecision(2);
    cout << "Valor convertido em dolar: " << valor_dolar << endl;
    cout << "Valor convertido em euro: " << valor_euro << endl;

    return 0;
}

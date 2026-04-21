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

    double total;
    if (!(cin >> total)) return 0;

    double pago_marco = total / 2.0;
    double pago_abril = pago_marco * 1.065;

    cout << fixed << setprecision(2);
    cout << "Valor total da fatura: R$ " << total << "\n";
    cout << "Valor a pagar em Marco: R$ " << pago_marco << "\n";
    cout << "Valor a pagar em Abril: R$ " << pago_abril << endl;

    return 0;
}
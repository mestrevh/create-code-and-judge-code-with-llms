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

    double kwh;
    cout << "Digite o valor real em KWh consumido:" << endl;
    
    if (cin >> kwh) {
        double valor_pago = kwh * 1.50;
        double valor_com_desconto = valor_pago * 0.85;

        cout << fixed << setprecision(2);
        cout << "Valor a ser pago: R$ " << valor_pago << " reais" << endl;
        cout << "Valor a ser pago com desconto: R$ " << valor_com_desconto << " reais" << endl;
    }

    return 0;
}
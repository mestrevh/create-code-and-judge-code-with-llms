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

    double valorCompra;
    if (!(cin >> valorCompra)) return 0;

    double valorVenda;
    if (valorCompra < 20.0) {
        valorVenda = valorCompra * 1.45;
    } else {
        valorVenda = valorCompra * 1.30;
    }

    cout << "Digite o valor de compra do produto:" << "\n";
    cout << "O produto deve ser vendido a R$ " << fixed << setprecision(2) << valorVenda << endl;

    return 0;
}
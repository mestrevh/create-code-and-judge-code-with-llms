/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    double valorCompra;
    cout << "Digite o valor de compra do produto:" << endl;
    
    if (cin >> valorCompra) {
        double valorVenda;
        if (valorCompra < 20.0) {
            valorVenda = valorCompra * 1.45;
        } else {
            valorVenda = valorCompra * 1.30;
        }
        cout << "O produto deve ser vendido a R$ " << valorVenda << endl;
    }

    return 0;
}
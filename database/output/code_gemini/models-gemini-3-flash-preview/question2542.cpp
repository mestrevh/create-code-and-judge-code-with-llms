/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    double reais;
    while (cin >> reais) {
        cout << "Digite o valor em reais:" << "\n";
        cout << "Valor convertido em dolar: " << reais / 3.87 << "\n";
        cout << "Valor convertido em euro: " << reais / 4.35 << "\n";
    }

    return 0;
}
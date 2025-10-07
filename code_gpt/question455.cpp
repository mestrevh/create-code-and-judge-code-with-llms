/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    double peso;
    cin >> peso;

    if (peso <= 20) {
        cout << fixed << setprecision(2) << 0.00 << endl;
    } else if (peso <= 25) {
        cout << fixed << setprecision(2) << (peso - 20) * 12.50 << endl;
    } else if (peso <= 30) {
        cout << fixed << setprecision(2) << (5 * 12.50 + (peso - 25) * 32.75) << endl;
    } else {
        cout << "PESO LIMITE EXCEDIDO" << endl;
    }

    return 0;
}

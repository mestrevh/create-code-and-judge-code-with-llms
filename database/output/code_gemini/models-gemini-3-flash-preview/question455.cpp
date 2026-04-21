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

    double weight;
    if (!(cin >> weight)) return 0;

    if (weight > 30.0) {
        cout << "PESO LIMITE EXCEDIDO" << endl;
    } else if (weight > 25.0) {
        double fee = (weight - 20.0) * 32.75;
        cout << fixed << setprecision(2) << fee << endl;
    } else if (weight > 20.0) {
        double fee = (weight - 20.0) * 12.50;
        cout << fixed << setprecision(2) << fee << endl;
    } else {
        cout << fixed << setprecision(2) << 0.00 << endl;
    }

    return 0;
}
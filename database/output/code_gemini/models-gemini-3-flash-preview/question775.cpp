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

    double massa, altura;
    if (!(cin >> massa >> altura)) return 0;

    double imc = massa / (altura * altura);

    cout << fixed << setprecision(2) << imc << " ";

    if (imc < 18.5) {
        cout << "MAGREZA" << endl;
    } else if (imc < 25.0) {
        cout << "SAUDAVEL" << endl;
    } else if (imc < 30.0) {
        cout << "SOBREPESO" << endl;
    } else {
        cout << "OBESIDADE" << endl;
    }

    return 0;
}
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

    double height, weight;
    if (!(cin >> height >> weight)) return 0;

    double imc = weight / (height * height);

    cout << fixed << setprecision(2) << imc << "\n";

    if (imc < 17.0) {
        cout << "Muito abaixo do peso" << "\n";
    } else if (imc < 18.5) {
        cout << "Abaixo do peso" << "\n";
    } else if (imc < 25.0) {
        cout << "Peso normal" << "\n";
    } else if (imc < 30.0) {
        cout << "Acima do peso" << "\n";
    } else if (imc < 35.0) {
        cout << "Obesidade grau I" << "\n";
    } else if (imc < 40.0) {
        cout << "Obesidade grau II" << "\n";
    } else {
        cout << "Obesidade grau III" << "\n";
    }

    return 0;
}
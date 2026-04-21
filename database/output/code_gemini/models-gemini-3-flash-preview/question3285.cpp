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

    double peso, altura;
    if (cin >> peso >> altura) {
        if (altura != 0) {
            double imc = peso / (altura * altura);
            cout << fixed << setprecision(1) << imc << endl;
        }
    }

    return 0;
}
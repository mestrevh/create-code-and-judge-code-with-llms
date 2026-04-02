/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    double n1, n2;
    string operacao;

    if (!(cin >> n1 >> n2 >> operacao)) return 0;

    double resultado = 0.0;

    if (operacao == "soma") {
        resultado = n1 + n2;
    } else if (operacao == "subtracao") {
        resultado = n1 - n2;
    } else if (operacao == "multiplicacao") {
        resultado = n1 * n2;
    } else if (operacao == "divisao") {
        if (n2 != 0) {
            resultado = n1 / n2;
        } else {
            resultado = 0.0;
        }
    }

    cout << "resultado = " << fixed << setprecision(2) << resultado << endl;

    return 0;
}
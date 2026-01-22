/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int main() {
    float num1, num2, resultado;
    string operacao;

    cin >> num1 >> num2 >> operacao;

    if (operacao == "soma") {
        resultado = num1 + num2;
    } else if (operacao == "subtracao") {
        resultado = num1 - num2;
    } else if (operacao == "multiplicacao") {
        resultado = num1 * num2;
    } else if (operacao == "divisao") {
        resultado = num1 / num2;
    }

    cout << "resultado = " << fixed << setprecision(2) << resultado << endl;

    return 0;
}

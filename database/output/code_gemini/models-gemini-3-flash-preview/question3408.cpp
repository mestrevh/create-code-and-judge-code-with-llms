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

    double salario;
    if (!(cin >> salario)) return 0;

    double bonificacao = 0.0;
    if (salario <= 5000.00) {
        bonificacao = salario * 0.05;
    } else if (salario <= 12000.00) {
        bonificacao = salario * 0.12;
    } else {
        bonificacao = 0.0;
    }

    double auxilio = 0.0;
    if (salario <= 6000.00) {
        auxilio = 150.00;
    } else {
        auxilio = 100.00;
    }

    double novo_salario = salario + bonificacao + auxilio;

    cout << fixed << setprecision(2) << novo_salario << endl;

    return 0;
}
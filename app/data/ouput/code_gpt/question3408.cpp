/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    double salario, bonificacao = 0, auxilio_escola = 0;

    cin >> salario;

    if (salario <= 5000) {
        bonificacao = salario * 0.05;
    } else if (salario <= 12000) {
        bonificacao = salario * 0.12;
    }

    if (salario <= 6000) {
        auxilio_escola = 150;
    } else {
        auxilio_escola = 100;
    }

    double novo_salario = salario + bonificacao + auxilio_escola;
    cout << fixed << setprecision(2) << novo_salario << endl;

    return 0;
}

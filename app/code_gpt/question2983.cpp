/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    double salario;
    cin >> salario;

    double desconto;
    if (salario <= 1320.00) {
        desconto = salario * 0.075;
    } else if (salario <= 2571.29) {
        desconto = salario * 0.09;
    } else if (salario <= 3875.57) {
        desconto = salario * 0.12;
    } else if (salario <= 7500.00) {
        desconto = salario * 0.14;
    } else {
        desconto = 0.11 * 7500.00;
    }

    cout << fixed << setprecision(2);
    cout << "Desconto do INSS: R$ " << desconto << endl;

    return 0;
}

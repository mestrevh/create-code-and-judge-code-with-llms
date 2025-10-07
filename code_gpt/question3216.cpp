/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    double salario, desconto;

    cin >> salario;

    if (salario <= 1100.00) {
        desconto = salario * 0.075;
    } else if (salario <= 2200.00) {
        desconto = 1100.00 * 0.075 + (salario - 1100.00) * 0.09;
    } else if (salario <= 3300.00) {
        desconto = 1100.00 * 0.075 + 1100.00 * 0.09 + (salario - 2200.00) * 0.12;
    } else if (salario <= 6433.57) {
        desconto = 1100.00 * 0.075 + 1100.00 * 0.09 + 1100.00 * 0.12 + (salario - 3300.00) * 0.14;
    } else {
        desconto = 1100.00 * 0.075 + 1100.00 * 0.09 + 1100.00 * 0.12 + 3133.57 * 0.14;
    }

    cout << fixed << setprecision(6);
    cout << "Desconto do INSS: R$ " << desconto << endl;

    return 0;
}

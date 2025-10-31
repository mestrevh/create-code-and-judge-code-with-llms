/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    double salario;
    int horasExtras;
    cin >> salario >> horasExtras;
    double pagamentoExtra = salario * 0.05 * horasExtras;
    cout << fixed << setprecision(2) << pagamentoExtra << endl;
    return 0;
}

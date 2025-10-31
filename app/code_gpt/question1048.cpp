/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    float salarioBase;
    int horasExtras;
    cin >> salarioBase >> horasExtras;

    float valorHora = salarioBase / 44;
    float adicional = valorHora * 1.1;
    float salarioFinal = salarioBase + (horasExtras * adicional);

    cout << fixed << setprecision(2) << salarioFinal << endl;
    return 0;
}

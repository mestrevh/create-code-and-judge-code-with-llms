/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    double peso, altura;
    cin >> peso >> altura;
    double imc = peso / (altura * altura);
    cout << fixed << setprecision(1) << imc << endl;
    return 0;
}

/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    double massa, altura, imc;
    cout << "Digite a massa em Kg:" << endl;
    cin >> massa;
    cout << "Digite a altura em m:" << endl;
    cin >> altura;
    imc = massa / (altura * altura);
    cout << fixed << setprecision(1) << "IMC = " << imc << endl;
    return 0;
}

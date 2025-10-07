/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    double m3, custoPorLitro;
    cin >> m3 >> custoPorLitro;

    double litros = m3 * 1000;
    double valorAgua = litros * custoPorLitro;
    double valorEsgoto = valorAgua * 0.8;
    double valorTotal = valorAgua + valorEsgoto;

    cout << fixed << setprecision(2);
    cout << valorAgua << endl;
    cout << valorEsgoto << endl;
    cout << valorTotal << endl;

    return 0;
}

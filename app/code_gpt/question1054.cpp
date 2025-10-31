/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    double raio, angulo;
    cin >> raio >> angulo;

    const double pi = 3.14;
    double comprimentoArco = (pi * raio * angulo) / 180.0;
    double areaSetor = (pi * raio * raio * angulo) / 360.0;

    cout << fixed << setprecision(2) << comprimentoArco << endl;
    cout << fixed << setprecision(2) << areaSetor << endl;

    return 0;
}

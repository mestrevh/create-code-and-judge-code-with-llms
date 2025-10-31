/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main() {
    int lados;
    double medida;

    cout << "Digite o numero de lados:" << endl;
    cin >> lados;
    cout << "Digite a medida do lado em cm:" << endl;
    cin >> medida;

    if (lados < 3) {
        cout << "NAO E UM POLIGONO" << endl;
    } else if (lados == 3) {
        double area = (sqrt(3) / 4) * medida * medida;
        cout << "TRIANGULO" << endl;
        cout << "A area do poligono e: " << fixed << setprecision(4) << area << " cm2" << endl;
    } else if (lados == 4) {
        double area = medida * medida;
        cout << "QUADRADO" << endl;
        cout << "A area do poligono e: " << fixed << setprecision(4) << area << " cm2" << endl;
    } else if (lados == 5) {
        cout << "PENTAGONO" << endl;
    } else {
        cout << "POLIGONO NAO IDENTIFICADO" << endl;
    }

    return 0;
}

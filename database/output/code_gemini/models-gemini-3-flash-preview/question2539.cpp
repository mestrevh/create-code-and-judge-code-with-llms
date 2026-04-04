/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    double l;
    while (cin >> n >> l) {
        cout << "Digite o numero de lados:" << "\n";
        cout << "Digite a medida do lado em cm:" << "\n";

        if (n < 3) {
            cout << "NAO E UM POLIGONO" << "\n";
        } else if (n == 3) {
            cout << "TRIANGULO" << "\n";
            double area = (l * l * sqrt(3.0)) / 4.0;
            cout << "A area do poligono e: " << area << " cm2" << "\n";
        } else if (n == 4) {
            cout << "QUADRADO" << "\n";
            double area = l * l;
            cout << "A area do poligono e: " << area << " cm2" << "\n";
        } else if (n == 5) {
            cout << "PENTAGONO" << "\n";
        } else {
            cout << "POLIGONO NAO IDENTIFICADO" << "\n";
        }
    }

    return 0;
}
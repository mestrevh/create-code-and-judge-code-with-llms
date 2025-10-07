/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {
    double lado;
    cin >> lado;

    double area = (3 * sqrt(3) / 2) * pow(lado, 2);
    double perimetro = 6 * lado;

    cout << fixed << setprecision(1);
    cout << "Lado do hexagono: " << lado << " metros,\n";
    cout << "Area: " << area << " metros quadrados,\n";
    cout << "Perimetro: " << perimetro << " metros." << endl;

    return 0;
}

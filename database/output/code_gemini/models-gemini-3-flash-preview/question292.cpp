/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    double A, B, C;
    if (!(cin >> A >> B >> C)) return 0;

    const double pi = 3.14159;

    double triangle = (A * C) / 2.0;
    double circle = pi * C * C;
    double trapezoid = ((A + B) * C) / 2.0;
    double square = B * B;
    double rectangle = A * B;

    cout << fixed << setprecision(3);
    cout << "TRIANGULO: " << triangle << "\n";
    cout << "CIRCULO: " << circle << "\n";
    cout << "TRAPEZIO: " << trapezoid << "\n";
    cout << "QUADRADO: " << square << "\n";
    cout << "RETANGULO: " << rectangle << endl;

    return 0;
}
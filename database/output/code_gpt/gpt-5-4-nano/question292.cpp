/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    double A, B, C;
    if (!(cin >> A >> B >> C)) return 0;

    double areaTriangulo = (A * C) / 2.0;
    double pi = 3.14159;
    double areaCirculo = pi * C * C;
    double areaTrapezio = (A + B) * C / 2.0;
    double areaQuadrado = B * B;
    double areaRetangulo = A * B;

    cout << fixed << setprecision(3);
    cout << "TRIANGULO: " << areaTriangulo << "\n";
    cout << "CIRCULO: " << areaCirculo << "\n";
    cout << "TRAPEZIO: " << areaTrapezio << "\n";
    cout << "QUADRADO: " << areaQuadrado << "\n";
    cout << "RETANGULO: " << areaRetangulo << "\n";

    return 0;
}
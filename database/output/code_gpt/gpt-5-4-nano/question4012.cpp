/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    double s;
    cout << "Digite o numero de lados: ";
    if (!(cin >> n)) return 0;
    cout << "Digite a medida do lado em cm: ";
    if (!(cin >> s)) return 0;

    cout << fixed << setprecision(4);

    if (n < 3) {
        cout << "NAO E UM POLIGONO";
        return 0;
    }

    if (n == 3) {
        double area = (sqrt(3.0) / 4.0) * s * s;
        cout << "TRIANGULO\n";
        cout << "A area do poligono e: " << area << " cm2";
        return 0;
    }

    if (n == 4) {
        double area = s * s;
        cout << "QUADRADO\n";
        cout << "A area do poligono e: " << area << " cm2";
        return 0;
    }

    if (n == 5) {
        cout << "PENTAGONO";
        return 0;
    }

    cout << "POLIGONO NAO IDENTIFICADA";
    return 0;
}
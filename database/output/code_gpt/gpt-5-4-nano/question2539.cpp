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
    double a;
    cout << "Digite o numero de lados:\n";
    if (!(cin >> n)) return 0;
    cout << "Digite a medida do lado em cm:\n";
    if (!(cin >> a)) return 0;

    cout.setf(ios::fixed);
    cout << setprecision(4);

    const double pi = acos(-1.0);
    if (n < 3) {
        cout << "NAO E UM POLIGONO\n";
        return 0;
    }

    if (n == 3) {
        double area = (3.0 * a * a) / (4.0 * tan(pi / 3.0));
        cout << "TRIANGULO\n";
        cout << "A area do poligono e: " << area << " cm2";
        return 0;
    }

    if (n == 4) {
        double area = (4.0 * a * a) / (4.0 * tan(pi / 4.0));
        cout << "QUADRADO\n";
        cout << "A area do poligono e: " << area << " cm2";
        return 0;
    }

    if (n == 5) {
        cout << "PENTAGONO\n";
        return 0;
    }

    cout << "POLIGONO NAO IDENTIFICADO\n";
    return 0;
}
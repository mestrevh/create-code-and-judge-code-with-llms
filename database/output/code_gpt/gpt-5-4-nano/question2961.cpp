/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    double L;
    if (!(cin >> L)) return 0;

    double area = (3.0 * (L * L) * sqrt(3.0)) / 2.0;
    double perim = 6.0 * L;

    cout << "Lado do hexagono: " << L << " metros,\n";
    cout << "Area: " << area << " metros quadrados,\n";
    cout << "Perimetro: " << perim << " metros.";
    return 0;
}
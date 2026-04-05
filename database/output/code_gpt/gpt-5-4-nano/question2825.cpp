/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    double X, Y;
    cout << "Digite as coordenadas (X, Y) separadas por ENTER:\n";
    if (!(cin >> X)) return 0;
    if (!(cin >> Y)) return 0;

    const double xMin = 0.0, xMax = 432.0;
    const double yMin = 0.0, yMax = 468.0;

    if (X >= xMin && X <= xMax && Y >= yMin && Y <= yMax) cout << "BOLA DENTRO";
    else cout << "BOLA FORA";

    return 0;
}
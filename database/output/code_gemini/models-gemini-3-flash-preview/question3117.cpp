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

    double x, z;
    if (!(cin >> x >> z)) return 0;

    double d_hogsmeade = sqrt((x - 34.0) * (x - 34.0) + (z - 220.0) * (z - 220.0));
    double d_kakariko = sqrt((x - 0.0) * (x - 0.0) + (z - 0.0) * (z - 0.0));
    double d_solitude = sqrt((x - 140.0) * (x - 140.0) + (z - 456.0) * (z - 456.0));

    cout << fixed << setprecision(2);
    cout << "Distancia para Hogsmeade: " << d_hogsmeade << "\n";
    cout << "Distancia para Kakariko: " << d_kakariko << "\n";
    cout << "Distancia para Solitude: " << d_solitude << "\n";

    return 0;
}
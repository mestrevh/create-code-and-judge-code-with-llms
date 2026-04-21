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

    double dh = sqrt(pow(x - 34, 2) + pow(z - 220, 2));
    double dk = sqrt(pow(x - 0, 2) + pow(z - 0, 2));
    double ds = sqrt(pow(x - 140, 2) + pow(z - 456, 2));

    cout << fixed << setprecision(2);
    cout << "Distancia para Hogsmeade: " << dh << "\n";
    cout << "Distancia para Kakariko: " << dk << "\n";
    cout << "Distancia para Solitude: " << ds << endl;

    return 0;
}
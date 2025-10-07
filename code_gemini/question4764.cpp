/*
Código criado pelo Gemini Pro 1.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    double a1, a2, b1, b2, c1, c2;
    char m1, m2;
    int d1, d2;

    cin >> a1 >> a2 >> b1 >> b2 >> c1 >> c2 >> m1 >> m2 >> d1 >> d2;

    double p1 = (a1 + b1 + c1) / 3.0;
    double p2 = (a2 + b2 + c2) / 3.0;

    char f1 = 'A' + (m1 - 'A' + d1 + 26) % 26;
    char f2 = 'A' + (m2 - 'A' + d2 + 26) % 26;

    cout << "A pista esta na coordenada: (" << fixed << setprecision(2) << p1 << ", " << fixed << setprecision(2) << p2 << ") e o cod e: " << f1 << f2 << endl;

    return 0;
}

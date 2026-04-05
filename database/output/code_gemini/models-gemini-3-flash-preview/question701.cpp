/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    double a, b, c;
    if (!(cin >> a >> b >> c)) return 0;

    const double EPS = 1e-9;

    if ((a + b > c + EPS) && (a + c > b + EPS) && (b + c > a + EPS)) {
        bool ab = (abs(a - b) < EPS);
        bool bc = (abs(b - c) < EPS);
        bool ac = (abs(a - c) < EPS);

        if (ab && bc) {
            cout << "EQUILATERO" << endl;
        } else if (ab || bc || ac) {
            cout << "ISOSCELES" << endl;
        } else {
            cout << "ESCALENO" << endl;
        }
    } else {
        cout << "-" << endl;
    }

    return 0;
}
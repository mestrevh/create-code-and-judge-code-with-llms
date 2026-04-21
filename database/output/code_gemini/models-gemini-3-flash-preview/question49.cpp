/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <cmath>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    double a, b, c;
    while (cin >> a >> b >> c) {
        bool ab = (abs(a - b) < 1e-9);
        bool bc = (abs(b - c) < 1e-9);
        bool ac = (abs(a - c) < 1e-9);

        if (ab && bc) {
            cout << "equilatero" << endl;
        } else if (ab || bc || ac) {
            cout << "isosceles" << endl;
        } else {
            cout << "escaleno" << endl;
        }
    }

    return 0;
}
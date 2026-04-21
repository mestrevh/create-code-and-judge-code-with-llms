/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    double x, y;
    if (!(cin >> x >> y)) return 0;

    double dxA = x - 1.0;
    double dyA = y - 1.0;
    double distSqA = dxA * dxA + dyA * dyA;

    double dxB = x - 2.0;
    double dyB = y - 1.0;
    double distSqB = dxB * dxB + dyB * dyB;

    const double EPS = 1e-11;
    bool inA = distSqA <= 1.0 + EPS;
    bool inB = distSqB <= 1.0 + EPS;

    if (inA && inB) {
        cout << "Interior A,B" << endl;
    } else if (inA) {
        cout << "Interior A" << endl;
    } else if (inB) {
        cout << "Interior B" << endl;
    } else {
        cout << "Exterior" << endl;
    }

    return 0;
}
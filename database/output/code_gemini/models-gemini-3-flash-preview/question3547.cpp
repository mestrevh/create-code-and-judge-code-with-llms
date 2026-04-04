/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    double a, b, c, d;
    while (cin >> a >> b >> c >> d) {
        // The spheroid x^2/a^2 + y^2/b^2 + z^2/b^2 = 1 has diameters 2a, 2b, 2b.
        // To fit it into a rectangle (c, d), we look for an orientation that minimizes the footprint.
        // The possible projections of this spheroid onto a plane are ellipses.
        // For this specific spheroid (a, b, b), the semi-axes (r1, r2) of any projection satisfy:
        // r1 = b
        // r2 is in [min(a, b), max(a, b)]
        // To minimize the footprint, we pick r2 = min(a, b).
        // Thus, the best footprint has diameters: 2*b and 2*min(a, b).

        double ship_d1 = 2.0 * b;
        double ship_d2 = 2.0 * min(a, b);

        double rect_min = (c < d) ? c : d;
        double rect_max = (c < d) ? d : c;

        double ship_min = (ship_d1 < ship_d2) ? ship_d1 : ship_d2;
        double ship_max = (ship_d1 < ship_d2) ? ship_d2 : ship_d1;

        if (ship_min <= rect_min && ship_max <= rect_max) {
            cout << "Pousa, bilu" << endl;
        } else {
            cout << "Procura outro lugar, bilu" << endl;
        }
    }

    return 0;
}
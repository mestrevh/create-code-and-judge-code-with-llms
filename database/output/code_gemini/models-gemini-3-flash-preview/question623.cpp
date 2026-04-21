/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    double x1, y1, x2, y2, x3, y3, x4, y4;
    while (cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4) {
        // Line 1: A1x + B1y = C1
        double a1 = y1 - y2;
        double b1 = x2 - x1;
        double c1 = a1 * x1 + b1 * y1;

        // Line 2: A2x + B2y = C2
        double a2 = y3 - y4;
        double b2 = x4 - x3;
        double c2 = a2 * x3 + b2 * y3;

        // Cramer's rule determinant
        double det = a1 * b2 - a2 * b1;

        if (std::abs(det) < 1e-10) {
            // Lines are parallel or coincident
            cout << "NUNCA" << "\n";
        } else {
            // Lines intersect at exactly one point
            double x = (c1 * b2 - c2 * b1) / det;
            double y = (a1 * c2 - a2 * c1) / det;

            // Normalize negative zeros for 0.00 output consistency
            if (std::abs(x) < 1e-7) x = 0.0;
            if (std::abs(y) < 1e-7) y = 0.0;

            cout << fixed << setprecision(2) << x << " " << y << "\n";
        }
    }

    return 0;
}
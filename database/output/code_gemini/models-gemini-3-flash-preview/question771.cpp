/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long double xp, yp;
    if (!(cin >> xp >> yp)) return 0;

    int n;
    if (!(cin >> n)) return 0;

    int rectCount = 0;
    int circCount = 0;

    for (int i = 0; i < n; ++i) {
        string type;
        if (!(cin >> type)) break;
        if (type == "retangulo") {
            long double xmin, ymin, xmax, ymax;
            if (cin >> xmin >> ymin >> xmax >> ymax) {
                if (xp >= xmin && xp <= xmax && yp >= ymin && yp <= ymax) {
                    rectCount++;
                }
            }
        } else if (type == "circulo") {
            long double xc, yc, r;
            if (cin >> xc >> yc >> r) {
                if (r < 0) r = -r;
                long double dx = xp - xc;
                long double dy = yp - yc;
                // Using a small epsilon to handle potential floating point precision errors
                // during squared distance comparison.
                if (dx * dx + dy * dy <= (r * r) + 1e-11L) {
                    circCount++;
                }
            }
        }
    }

    cout << "Retangulos: " << rectCount << "\n";
    cout << "Circulos: " << circCount << "\n";

    return 0;
}

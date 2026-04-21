/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    double v, c;
    int d;

    if (!(cin >> v >> c >> d)) return 0;

    if (d < 0) {
        cout << "Vai pa onde, kinho?" << endl;
    } else if (v < 75.0) {
        cout << "Zilboi trollou o kinho" << endl;
    } else {
        double fuel_needed = 0;
        if (d > 5) {
            double dist_left = (double)d - 5.0;
            double current_v = v - 10.0;
            double current_eff = 13.0;
            bool locked = false;

            if (current_v < 50.0) {
                locked = true;
                current_eff = 10.0;
            }

            while (dist_left > 1e-9) {
                double step = (dist_left < 2.5) ? dist_left : 2.5;
                fuel_needed += step / current_eff;
                dist_left -= step;

                if (!locked && dist_left > 1e-9) {
                    current_v -= 5.0;
                    current_eff -= 0.5;
                    if (current_v < 50.0) {
                        locked = true;
                        current_eff = 10.0;
                    }
                }
            }
        }

        if (fuel_needed <= c + 1e-9) {
            cout << "Parabens, Kinho. Vc vai comer um morceguinho." << endl;
        } else {
            cout << "Pobre Kinho. Vai ficar no meio do caminho." << endl;
        }
    }

    return 0;
}
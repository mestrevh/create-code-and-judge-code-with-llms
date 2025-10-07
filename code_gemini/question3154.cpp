/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <iomanip>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    double v, c;
    int d_int;
    cin >> v >> c >> d_int;

    double d = static_cast<double>(d_int);

    if (d < 0) {
        cout << "Vai pa onde, kinho?\n";
        return 0;
    }

    if (v < 75.0) {
        cout << "Zilboi trollou o kinho\n";
        return 0;
    }

    if (d <= 5.0) {
        cout << "Parabens, Kinho. Vc vai comer um morceguinho.\n";
        return 0;
    }

    d -= 5.0;
    v -= 10.0;

    double consumption = 13.0;
    bool battery_active = true;

    while (d > 1e-9) {
        if (battery_active && v < 50.0) {
            battery_active = false;
            consumption = 10.0;
        }

        double step_distance;
        if (battery_active) {
            step_distance = min(d, 2.5);
        } else {
            step_distance = d;
        }

        double fuel_needed = step_distance / consumption;

        if (fuel_needed > c) {
            cout << "Pobre Kinho. Vai ficar no meio do caminho.\n";
            return 0;
        }

        c -= fuel_needed;
        d -= step_distance;

        if (battery_active) {
            v -= 5.0;
            consumption -= 0.5;
        }
    }

    cout << "Parabens, Kinho. Vc vai comer um morceguinho.\n";

    return 0;
}

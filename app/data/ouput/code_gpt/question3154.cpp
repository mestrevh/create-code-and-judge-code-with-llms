/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    double V, C;
    int D;
    cin >> V >> C >> D;

    if (D < 0) {
        cout << "Vai pa onde, kinho?" << endl;
        return 0;
    }
    if (V < 75) {
        cout << "Zilboi trollou o kinho" << endl;
        return 0;
    }

    double distance_left = D;
    double fuel_used = 0;
    double consumption = 0;

    if (D <= 5) {
        cout << "Parabens, Kinho. Vc vai comer um morceguinho." << endl;
        return 0;
    } else {
        distance_left -= 5;
        V -= 10;
        consumption = 13;
    }

    while (distance_left > 0) {
        if (V < 50) {
            consumption = 10;
        } else {
            if (distance_left >= 2.5) {
                distance_left -= 2.5;
                fuel_used += 2.5 / consumption;
                consumption -= 0.5;
                V -= 5;
            } else {
                fuel_used += distance_left / consumption;
                distance_left = 0;
            }
        }

        if (fuel_used > C) {
            cout << "Pobre Kinho. Vai ficar no meio do caminho." << endl;
            return 0;
        }
    }

    cout << "Parabens, Kinho. Vc vai comer um morceguinho." << endl;
    return 0;
}

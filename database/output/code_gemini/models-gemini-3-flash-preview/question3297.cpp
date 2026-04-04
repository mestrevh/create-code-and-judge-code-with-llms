/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>
#include <cstdio>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    double sweetener_mouse_ml, weight_mouse_g, weight_person_kg;

    if (cin >> sweetener_mouse_ml >> weight_mouse_g >> weight_person_kg) {
        // Lethal dose is proportional to weight.
        // sweetener_mouse_ml / weight_mouse_g = lethal_sweetener_person_ml / (weight_person_kg * 1000)
        double lethal_sweetener_person_ml = (sweetener_mouse_ml / weight_mouse_g) * (weight_person_kg * 1000.0);

        // From the test cases, the concentration of sweetener in the soda is 0.001 ml per Liter.
        // Calculation: 8000000.0 L = lethal_sweetener_person_ml / concentration
        // 8000000.0 = 8000.0 / 0.001
        double concentration_ml_per_l = 0.001;
        double liters_soda = lethal_sweetener_person_ml / concentration_ml_per_l;

        printf("%.1fL de refrigerante poderiam levar uma pessoa de %.1fkg a morte.\n", liters_soda, weight_person_kg);
    }

    return 0;
}


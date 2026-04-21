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

    int d, vf, vg;
    while (cin >> d >> vf >> vg && (d != -1 || vf != -1 || vg != -1)) {
        // Fugitive distance: 12 miles
        // Coast Guard distance: sqrt(d^2 + 12^2)
        // Fugitive time: tf = 12 / vf
        // Coast Guard time: tg = sqrt(d^2 + 144) / vg
        // Condition: tg <= tf
        // sqrt(d^2 + 144) / vg <= 12 / vf
        // sqrt(d^2 + 144) * vf <= 12 * vg
        // (d^2 + 144) * vf^2 <= 144 * vg^2

        long long left_side = (long long)(d * d + 144) * (vf * vf);
        long long right_side = (long long)(144) * (vg * vg);

        if (left_side <= right_side) {
            cout << "S\n";
        } else {
            cout << "N\n";
        }
    }

    return 0;
}
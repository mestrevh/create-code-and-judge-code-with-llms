/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    double d;
    if (!(cin >> d)) return 0;

    double costs[4];
    double eff[4] = {75.0, 50.0, 25.0, 50.0};
    double cb[4];
    double sum_cb = 0.0;

    for (int i = 0; i < 4; i++) {
        if (!(cin >> costs[i])) break;
        cb[i] = eff[i] / costs[i];
        sum_cb += cb[i];
    }

    double average_cb = sum_cb / 4.0;

    for (int i = 0; i < 4; i++) {
        if (costs[i] > d) {
            cout << "foi de comes" << "\n";
        } else if (cb[i] < average_cb) {
            cout << "EH BOMBA TORRESMO" << "\n";
        } else {
            cout << "eh dento" << "\n";
        }
    }

    return 0;
}
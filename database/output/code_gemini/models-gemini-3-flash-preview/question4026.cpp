/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long double a[2], b[2];
    char x[2];

    for (int i = 0; i < 2; ++i) {
        if (!(cin >> a[i] >> b[i] >> x[i])) break;
    }

    long double val[2], unc[2];
    for (int i = 0; i < 2; ++i) {
        long double factor = 1.0;
        if (x[i] == 'd') {
            factor = 0.1;
        } else if (x[i] == 'c') {
            factor = 0.01;
        }
        val[i] = a[i] * factor;
        unc[i] = b[i] * factor;
    }

    long double diff = fabsl(val[0] - val[1]);
    long double sum_unc = unc[0] + unc[1];

    if (diff <= sum_unc + 1e-11) {
        cout << "forte." << "\n";
    } else {
        cout << "isso tem cara de desencadear um evento de distorcao espacial na proxima questao do meme man..." << "\n";
    }

    return 0;
}
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

    int n;
    if (!(cin >> n)) return 0;

    double s = 0.0;
    for (int i = 0; i < n; ++i) {
        double denom = 2.0 * i + 1.0;
        double term = 1.0 / (denom * denom * denom);
        if (i % 2 == 0) {
            s += term;
        } else {
            s -= term;
        }
    }

    double pi = pow(s * 32.0, 1.0 / 3.0);

    cout << fixed << setprecision(5) << pi << endl;

    return 0;
}
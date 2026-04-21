/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string scale;
    double t;
    if (!(cin >> scale >> t)) return 0;

    const double minC = -273.15;
    const double minF = -459.67;
    const double minK = 0.0;

    auto printVal = [](double v) {
        cout.setf(ios::fixed);
        cout << setprecision(2) << v;
    };

    if (scale == "C") {
        if (t < minC) {
            cout << "Valor de temperatura abaixo do minimo";
            return 0;
        }
        double f = t * 9.0 / 5.0 + 32.0;
        double k = t + 273.15;
        printVal(f); cout << " F\n";
        printVal(k); cout << " K";
    } else if (scale == "F") {
        if (t < minF) {
            cout << "Valor de temperatura abaixo do minimo";
            return 0;
        }
        double c = (t - 32.0) * 5.0 / 9.0;
        double k = c + 273.15;
        printVal(c); cout << " C\n";
        printVal(k); cout << " K";
    } else if (scale == "K") {
        if (t < minK) {
            cout << "Valor de temperatura abaixo do minimo";
            return 0;
        }
        double c = t - 273.15;
        double f = c * 9.0 / 5.0 + 32.0;
        printVal(f); cout << " F\n";
        printVal(c); cout << " C";
    }

    return 0;
}
/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string scale;
    double temp;

    if (!(cin >> scale >> temp)) return 0;

    cout << fixed << setprecision(2);

    if (scale == "C") {
        if (temp < -273.15) {
            cout << "Valor de temperatura abaixo do minimo" << endl;
        } else {
            double f = temp * 1.8 + 32.0;
            double k = temp + 273.15;
            cout << f << " F" << endl;
            cout << k << " K" << endl;
        }
    } else if (scale == "F") {
        if (temp < -459.67) {
            cout << "Valor de temperatura abaixo do minimo" << endl;
        } else {
            double c = (temp - 32.0) / 1.8;
            double k = c + 273.15;
            cout << c << " C" << endl;
            cout << k << " K" << endl;
        }
    } else if (scale == "K") {
        if (temp < 0.0) {
            cout << "Valor de temperatura abaixo do minimo" << endl;
        } else {
            double c = temp - 273.15;
            double f = c * 1.8 + 32.0;
            cout << f << " F" << endl;
            cout << c << " C" << endl;
        }
    }

    return 0;
}


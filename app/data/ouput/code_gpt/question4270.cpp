/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

int main() {
    string scale;
    double value;
    
    cin >> scale >> value;

    if (scale == "C") {
        double F = (value * 1.8) + 32;
        double K = value + 273.15;
        cout << fixed << setprecision(1) << F << " F" << endl;
        cout << fixed << setprecision(2) << K << " K" << endl;
    } else if (scale == "K") {
        double C = value - 273.15;
        double F = (C * 1.8) + 32;
        cout << fixed << setprecision(1) << C << " C" << endl;
        cout << fixed << setprecision(1) << F << " F" << endl;
    } else if (scale == "F") {
        double C = (value - 32) / 1.8;
        double K = C + 273.15;
        cout << fixed << setprecision(1) << C << " C" << endl;
        cout << fixed << setprecision(2) << K << " K" << endl;
    }

    return 0;
}

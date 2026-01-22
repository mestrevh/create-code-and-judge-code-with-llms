/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int main() {
    string escala;
    double temperatura;
    cin >> escala >> temperatura;

    if ((escala == "C" && temperatura < -273.15) ||
        (escala == "F" && temperatura < -459.67) ||
        (escala == "K" && temperatura < 0.0)) {
        cout << "Valor de temperatura abaixo do minimo" << endl;
        return 0;
    }

    if (escala == "C") {
        double f = (temperatura * 9.0 / 5.0) + 32.0;
        double k = temperatura + 273.15;
        cout << fixed << setprecision(2) << f << " F" << endl;
        cout << fixed << setprecision(2) << k << " K" << endl;
    } else if (escala == "F") {
        double c = (temperatura - 32.0) * 5.0 / 9.0;
        double k = c + 273.15;
        cout << fixed << setprecision(2) << c << " C" << endl;
        cout << fixed << setprecision(2) << k << " K" << endl;
    } else if (escala == "K") {
        double c = temperatura - 273.15;
        double f = (c * 9.0 / 5.0) + 32.0;
        cout << fixed << setprecision(2) << c << " C" << endl;
        cout << fixed << setprecision(2) << f << " F" << endl;
    }

    return 0;
}

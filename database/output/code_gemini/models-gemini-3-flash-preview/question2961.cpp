/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <cmath>
#include <iomanip>
#include <string>
#include <sstream>

using namespace std;

string format_python(double v) {
    stringstream ss;
    ss << setprecision(16) << v;
    string s = ss.str();
    if (s.find('.') == string::npos && s.find('e') == string::npos) {
        s += ".0";
    }
    return s;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    double l;
    if (cin >> l) {
        double area = (3.0 * (l * l) * sqrt(3.0)) / 2.0;
        double perimeter = 6.0 * l;

        cout << "Lado do hexagono: " << format_python(l) << " metros," << endl;
        cout << "Area: " << format_python(area) << " metros quadrados," << endl;
        cout << "Perimetro: " << format_python(perimeter) << " metros." << endl;
    }

    return 0;
}
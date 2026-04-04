/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>

using namespace std;

string format_py(double x) {
    ostringstream oss;
    oss << x;
    string s = oss.str();
    if (s.find('.') == string::npos && s.find('e') == string::npos) {
        s += ".0";
    }
    return s;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    double f;
    if (cin >> f) {
        double c = (f - 32.0) * 5.0 / 9.0;
        double k = c + 273.15;

        cout << "Convertendo " << format_py(f) << " °F temos:\n";
        cout << format_py(c) << " °C e " << format_py(k) << " K\n";
    }

    return 0;
}
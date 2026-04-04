/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string scale;
    double val;

    if (cin >> scale >> val) {
        char s = scale[0];

        if (s == 'C' || s == 'c') {
            double f = val * 1.8 + 32.0;
            double k = val + 273.15;
            cout << f << " F" << endl;
            cout << k << " K" << endl;
        } else if (s == 'K' || s == 'k') {
            double c = val - 273.15;
            double f = c * 1.8 + 32.0;
            cout << c << " C" << endl;
            cout << f << " F" << endl;
        } else if (s == 'F' || s == 'f') {
            double c = (val - 32.0) / 1.8;
            double k = c + 273.15;
            cout << c << " C" << endl;
            cout << k << " K" << endl;
        }
    }

    return 0;
}
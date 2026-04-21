/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <sstream>

using namespace std;

string fp(double val) {
    ostringstream oss;
    oss << setprecision(17) << val;
    string s = oss.str();
    if (s.find('.') == string::npos && s.find('e') == string::npos) {
        s += ".0";
    }
    return s;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    double n;
    if (cin >> n) {
        double pi = acos(-1.0);
        double e = exp(1.0);

        cout << "i) " << fp(n * n) << "\n";
        cout << "ii) " << fp(pow(n, e)) << "\n";
        cout << "iii) " << fp(pow(n, 0.5)) << "\n";
        cout << "iv) " << fp(pow(n, 1.0 / 3.0)) << "\n";
        cout << "v) " << fp(pow(n, 1.0 / n)) << "\n";
        cout << "vi) " << fp(n * e) << "\n";
        cout << "vii) " << fp(pi / n) << "\n";
        cout << "viii) " << fp(log(n) / log(7.0)) << "\n";
        cout << "ix) " << fp(log(n)) << "\n";
        cout << "x) " << fp(log(n) / log(pi)) << "\n";
    }

    return 0;
}
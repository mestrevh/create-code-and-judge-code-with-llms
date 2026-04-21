/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <iomanip>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;

    auto readVal = []() {
        string s;
        if (!(cin >> s)) return 0.0;
        for (char &c : s) {
            if (c == ',') c = '.';
        }
        try {
            return stod(s);
        } catch (...) {
            return 0.0;
        }
    };

    vector<double> u(n);
    for (int i = 0; i < n; ++i) {
        u[i] = readVal();
    }

    vector<double> v(n);
    for (int i = 0; i < n; ++i) {
        v[i] = readVal();
    }

    bool identical = true;
    for (int i = 0; i < n; ++i) {
        if (abs(u[i] - v[i]) > 1e-9) {
            identical = false;
            break;
        }
    }

    if (identical) {
        cout << "Os vetores sao iguais, logo, a projecao de v na direcao de u, eh o proprio u." << endl;
    } else {
        double dot_vu = 0;
        double dot_uu = 0;
        for (int i = 0; i < n; ++i) {
            dot_vu += v[i] * u[i];
            dot_uu += u[i] * u[i];
        }

        double scalar = (dot_uu == 0) ? 0.0 : (dot_vu / dot_uu);

        cout << "A projecao ortogonal de v na direcao de u eh:" << endl;
        cout << fixed << setprecision(3);
        for (int i = 0; i < n; ++i) {
            double res = scalar * u[i];
            if (abs(res) < 1e-9) res = 0.0;
            cout << "| " << res << " |" << endl;
        }
    }

    return 0;
}
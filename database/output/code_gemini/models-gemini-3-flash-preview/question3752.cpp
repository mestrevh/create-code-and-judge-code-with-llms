/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

void equacaoredx(int c, float e) {
    double dv_c = (double)c;
    double dv_e = (double)e;
    double a2 = (dv_c * dv_c) / (dv_e * dv_e);
    double b2 = a2 - (dv_c * dv_c);
    cout << "FOCOS EM X" << endl;
    cout << "x^2/" << a2 << " + y^2/" << b2 << " = 1" << endl;
}

void equacaoredy(int c, float e) {
    double dv_c = (double)c;
    double dv_e = (double)e;
    double a2 = (dv_c * dv_c) / (dv_e * dv_e);
    double b2 = a2 - (dv_c * dv_c);
    cout << "FOCOS EM Y" << endl;
    cout << "x^2/" << b2 << " + y^2/" << a2 << " = 1" << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int x1, y1, x2, y2;
    float e;

    if (cin >> x1 >> y1 >> x2 >> y2 >> e) {
        if (y1 == 0 && y2 == 0) {
            equacaoredx(abs(x1), e);
        } else {
            equacaoredy(abs(y1), e);
        }
    }

    return 0;
}
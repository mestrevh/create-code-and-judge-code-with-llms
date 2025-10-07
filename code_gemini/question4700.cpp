/*
Código criado pelo Gemini Pro 1.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

void maior_numero(double a, double b) {
    if (a == b) {
        cout << "São iguais" << endl;
    } else if (a > b) {
        if (abs(a - round(a)) < 1e-9) {
            cout << fixed << setprecision(0) << a << endl;
        } else {
            cout << fixed << setprecision(1) << a << endl;
        }
    } else {
        if (abs(b - round(b)) < 1e-9) {
            cout << fixed << setprecision(0) << b << endl;
        } else {
            cout << fixed << setprecision(1) << b << endl;
        }
    }
}

int main() {
    double a, b;
    cin >> a >> b;
    maior_numero(a, b);
    return 0;
}

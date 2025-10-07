/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main() {
    double a, b, c;
    cin >> a >> b >> c;

    if (a == 0) {
        cout << "NEESG" << endl;
    } else {
        double delta = b * b - 4 * a * c;
        if (delta < 0) {
            cout << "NRR" << endl;
        } else {
            double r1 = (-b + sqrt(delta)) / (2 * a);
            double r2 = (-b - sqrt(delta)) / (2 * a);
            if (delta == 0) {
                cout << fixed << setprecision(2) << r1 << endl;
            } else {
                cout << fixed << setprecision(2) << min(r1, r2) << endl;
                cout << fixed << setprecision(2) << max(r1, r2) << endl;
            }
        }
    }
    return 0;
}

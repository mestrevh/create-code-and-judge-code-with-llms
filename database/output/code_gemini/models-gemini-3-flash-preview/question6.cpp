/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    double a, b, c;
    if (!(cin >> a >> b >> c)) return 0;

    if (a == 0) {
        cout << "NEESG" << endl;
    } else {
        double delta = b * b - 4.0 * a * c;
        if (delta < 0) {
            cout << "NRR" << endl;
        } else {
            double sqrt_delta = sqrt(delta);
            double x1 = (-b + sqrt_delta) / (2.0 * a);
            double x2 = (-b - sqrt_delta) / (2.0 * a);
            
            cout << fixed << setprecision(2) << x1 << "\n";
            cout << fixed << setprecision(2) << x2 << "\n";
        }
    }

    return 0;
}
/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main() {
    int n;
    cin >> n;

    double pi = M_PI;

    // Equação 1
    for (int i = 0; i < 3; ++i) {
        double result = 0.0;
        for (int x = 0; x <= n; ++x) {
            result += (pow(-1, x) / (2 * x + 1));
        }
        result *= 4;
        cout << fixed << setprecision(6) << result << " - " << (result / pi) * 100 << endl;

        // Equação 2
        result = 0.0;
        for (int x = 0; x <= n; ++x) {
            result += (2.0 / ((4 * x + 1) * (4 * x + 3)));
        }
        result *= 4;
        cout << fixed << setprecision(6) << result << " - " << (result / pi) * 100 << endl;

        // Equação 3
        result = 3.0;
        for (int x = 1; x <= n; ++x) {
            if (x % 2 == 1)
                result += 4.0 / ((2 * x) * (2 * x + 1) * (2 * x + 2));
            else
                result -= 4.0 / ((2 * x) * (2 * x + 1) * (2 * x + 2));
        }
        cout << fixed << setprecision(6) << result << " - " << (result / pi) * 100 << endl;
    }

    return 0;
}

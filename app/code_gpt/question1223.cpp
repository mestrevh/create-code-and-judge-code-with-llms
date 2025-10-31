/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

double calculateC(int X, int T) {
    double C = 0.0;
    for (int n = 0; n < T; n++) {
        double term = pow(X, 2 * n) / tgamma(2 * n + 1);
        C += (n % 2 == 0 ? term : -term);
    }
    return C;
}

int main() {
    int X, T;
    while (true) {
        cin >> X >> T;
        if (X == 0 && T == 0) break;
        double result = calculateC(X, T);
        cout << fixed << setprecision(10) << fabs(result) << endl;
    }
    return 0;
}

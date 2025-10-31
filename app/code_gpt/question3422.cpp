/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {
    int n;
    cin >> n;

    double S = 0.0;
    for (int k = 0; k < n; ++k) {
        S += pow(-1, k) / (2 * k + 1);
    }

    double pi = pow(S * 32, 1.0 / 3.0);
    cout << fixed << setprecision(5) << pi << endl;

    return 0;
}

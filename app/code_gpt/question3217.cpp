/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {
    double graus, radianos, seno = 0.0, cosseno = 0.0;
    int n;
    cin >> graus >> n;

    radianos = graus * M_PI / 180.0;

    for (int i = 0; i < n; i++) {
        seno += (pow(-1, i) * pow(radianos, 2 * i + 1)) / tgamma(2 * i + 2);
        cosseno += (pow(-1, i) * pow(radianos, 2 * i)) / tgamma(2 * i + 1);
    }

    cout << fixed << setprecision(5) << seno << endl;
    cout << fixed << setprecision(5) << cosseno << endl;

    return 0;
}

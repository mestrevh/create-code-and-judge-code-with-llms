/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

double VolumeEsfera(double raio) {
    return (4.0 / 3.0) * 3.1416 * pow(raio, 3);
}

int main() {
    double raio;
    for (int i = 0; i < 3; i++) {
        cin >> raio;
        cout << fixed << setprecision(2) << VolumeEsfera(raio) << endl;
    }
    return 0;
}

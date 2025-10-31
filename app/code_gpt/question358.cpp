/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <cmath>

using namespace std;

double calcularPrestacao(double F, int n, double t) {
    double an = (pow(1 + t, n) - 1) / (t * pow(1 + t, n));
    return F / an;
}

int main() {
    double F, t;
    int n;
    cin >> F >> n >> t;
    cout << static_cast<int>(round(calcularPrestacao(F, n, t))) << endl;
    return 0;
}

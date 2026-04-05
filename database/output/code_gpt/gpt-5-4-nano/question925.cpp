/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

static bool equalsWithin(double a, double b, double eps = 1e-9) {
    return fabs(a - b) <= eps * max(1.0, max(fabs(a), fabs(b)));
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    double a, b, c;
    if (!(cin >> a)) return 0;
    cin >> b >> c;

    cout << "Informe o comprimento do primeiro lado do triangulo:\n";
    cout << "Informe o comprimento do segundo lado do triangulo:\n";
    cout << "Informe o comprimento do terceiro lado do triangulo:\n";

    bool can = (a + b > c) && (a + c > b) && (b + c > a);
    if (!can) {
        cout << "Os lados informados nao podem formar um triangulo\n";
        return 0;
    }

    cout << "Os lados informados podem formar um triangulo\n";

    bool ab = equalsWithin(a, b);
    bool ac = equalsWithin(a, c);
    bool bc = equalsWithin(b, c);

    if (ab && ac) {
        cout << "Triangulo Equilatero\n";
    } else if (ab || ac || bc) {
        cout << "Triangulo Isosceles\n";
    } else {
        cout << "Triangulo Escaleno\n";
    }

    return 0;
}
/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

double maior_numero(double a, double b, bool &igual) {
    igual = false;
    if (a == b) {
        igual = true;
        return a;
    }
    return (a > b) ? a : b;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    double a, b;
    if (!(cin >> a >> b)) return 0;

    bool igual = false;
    double m = maior_numero(a, b, igual);

    cout.setf(ios::fixed);
    cout << setprecision(1);

    if (igual) cout << "São iguais";
    else cout << m;

    return 0;
}
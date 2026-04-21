/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long double numero;
    if (!(cin >> numero)) return 0;

    long double piso = floorl(numero);
    long double teto = ceill(numero);
    long double raiz = sqrtl(numero);
    long double seno = sinl(numero);
    long double cosseno = cosl(numero);
    long double pot3 = numero * numero * numero;

    cout.setf(ios::fixed);
    cout << setprecision(6);
    cout << "numero=" << (double)numero << "\n";
    cout << "piso=" << (double)piso << "\n";
    cout << "teto=" << (double)teto << "\n";
    cout << "raiz=" << (double)raiz << "\n";
    cout << "seno=" << (double)seno << "\n";
    cout << "cosseno=" << (double)cosseno << "\n";
    cout << "pot3=" << (double)pot3 << "\n";
    return 0;
}
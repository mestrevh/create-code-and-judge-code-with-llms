/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long double a;
    if (!(cin >> a)) return 0;

    long double area = a * a;
    long double dobro = 2 * area;

    cout << fixed << setprecision(1);
    cout << "Informe a medida de um dos lados do quadrado:\n";
    cout << "Resultado: " << (double)area << "\n";
    cout << "Dobro: " << (double)dobro << "\n";
    return 0;
}
/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    double a, b, c;
    cout << "Digite o comprimento do lado A:\n";
    if (!(cin >> a)) return 0;
    cout << "Digite o comprimento do lado B:\n";
    cin >> b;
    cout << "Digite o comprimento do lado C:\n";
    cin >> c;

    cout << "Este e um triangulo ";
    if (a == b && b == c) cout << "equilatero.";
    else if (a == b || a == c || b == c) cout << "isosceles.";
    else cout << "escaleno.";

    return 0;
}
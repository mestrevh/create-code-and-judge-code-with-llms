/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long a, b, c;
    if (!(cin >> a >> b >> c)) return 0;

    if (a <= 0 || b <= 0 || c <= 0) {
        cout << "Nao eh triangulo";
        return 0;
    }

    if (a + b <= c || a + c <= b || b + c <= a) {
        cout << "Nao eh triangulo";
        return 0;
    }

    if (a == b && b == c) {
        cout << "Equilatero";
    } else if (a == b || a == c || b == c) {
        cout << "Isosceles";
    } else {
        cout << "Escaleno";
    }
    return 0;
}
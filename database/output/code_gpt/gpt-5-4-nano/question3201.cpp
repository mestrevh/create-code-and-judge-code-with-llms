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
    if (!(cin >> a >> b >> c)) return 0;

    double soma_quad = a*a + b*b + c*c;
    double soma = a + b + c;
    double quad_soma = soma * soma;

    cout << fixed << setprecision(1) << soma_quad << "\n" << quad_soma << "\n";
    return 0;
}
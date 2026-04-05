/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

double somar(double a, double b) {
    return a + b;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    double a, b;
    if (!(cin >> a >> b)) return 0;

    double c = somar(a, b);

    cout << "O resultado de " << fixed << setprecision(1) << a
         << " + " << fixed << setprecision(1) << b
         << " eh " << fixed << setprecision(1) << c;
    return 0;
}
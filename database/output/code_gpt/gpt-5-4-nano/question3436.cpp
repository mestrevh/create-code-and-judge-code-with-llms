/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

long double areaCirculo(long double r) {
    const long double pi = acosl(-1.0L);
    return pi * r * r;
}

long double perimetroCirculo(long double r) {
    const long double pi = acosl(-1.0L);
    return 2.0L * pi * r;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long double r;
    if (!(cin >> r)) return 0;

    cout << fixed << setprecision(5) << (double)areaCirculo(r) << "\n";
    cout << fixed << setprecision(5) << (double)perimetroCirculo(r) << "\n";
    return 0;
}
/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    long double h, r, cost;
    if (!(cin >> h >> r >> cost)) return 0;

    const long double pi = acosl(-1.0L);
    long double area = 2.0L * (pi * r * r) + (2.0L * pi * r) * h;
    long double litros = area / 3.0L;
    long double latas = litros / 5.0L;
    long double custoTotal = latas * cost;

    cout.setf(std::ios::fixed);
    cout << setprecision(6) << area << "m2\n";
    cout << setprecision(6) << litros << "l\n";
    cout << setprecision(6) << latas << "\n";
    cout << "R$" << setprecision(6) << custoTotal << "\n";
    return 0;
}
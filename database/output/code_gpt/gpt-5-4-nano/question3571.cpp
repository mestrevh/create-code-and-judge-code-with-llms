/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long double h, r;
    if (!(cin >> h >> r)) return 0;

    const long double pricePerCan = 20.0L;
    const long double litersPerCan = 5.0L;
    const long double areaPerLiter = 3.0L;

    const long double area = 2.0L * M_PI * r * (r + h);
    const long double litersNeeded = area / areaPerLiter;
    long long cans = (long long) ceill(litersNeeded / litersPerCan - 1e-18L);

    long double totalCost = cans * pricePerCan;

    cout.setf(std::ios::fixed);
    cout << setprecision(2);

    cout << "custo = R$ " << (double)totalCost << "\n";
    cout << "quantidade de latas = " << cans << "\n";
    return 0;
}
/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long double m3, costPerLiter;
    if (!(cin >> m3 >> costPerLiter)) return 0;

    long double liters = m3 * 1000.0L;
    long double water = liters * costPerLiter;
    long double sewer = water * 0.8L;
    long double total = water + sewer;

    cout << fixed << setprecision(2);
    cout << (double)water << "\n";
    cout << (double)sewer << "\n";
    cout << (double)total << "\n";

    return 0;
}
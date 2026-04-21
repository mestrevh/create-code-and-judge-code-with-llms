/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    double treeValue;
    if (!(cin >> treeValue)) return 0;

    const int employees = 21;

    double decorationsTotal = 0.0;
    for (int i = 0; i < 3; i++) {
        long long qty;
        double price;
        cin >> qty >> price;
        decorationsTotal += static_cast<double>(qty) * price;
    }

    double total = treeValue + decorationsTotal;
    double perEmployee = total / employees;

    cout << fixed << setprecision(2) << total << "\n" << perEmployee << "\n";
    return 0;
}
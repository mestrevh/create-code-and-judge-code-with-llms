/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    double t, v;
    if (!(cin >> t >> v)) return 0;

    double distance = t * v;
    double liters = distance / 12.0;

    cout << fixed << setprecision(3) << liters << "\n";
    return 0;
}
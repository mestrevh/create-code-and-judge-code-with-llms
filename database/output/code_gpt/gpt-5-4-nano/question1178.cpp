/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int V, P;
    if (!(cin >> V >> P)) return 0;

    const double pi = 3.14;

    double rV = 0.5 / 2.0;
    double rP = 0.07 / 2.0;

    double volV = (4.0 / 3.0) * pi * rV * rV * rV;
    double volP = (4.0 / 3.0) * pi * rP * rP * rP;

    double totalVol = V * volV + P * volP;

    double baseArea = 5.0 * 4.0;
    double H = totalVol / baseArea * 100.0;

    cout.setf(std::ios::fixed);
    cout << setprecision(1) << "Altura da piscina aumentou: " << H << " cm";
    return 0;
}
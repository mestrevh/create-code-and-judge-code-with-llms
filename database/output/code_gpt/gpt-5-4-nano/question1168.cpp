/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    long long V, P;
    if (!(cin >> V >> P)) return 0;

    const double pi = 3.14;
    const double A = 5.0;
    const double B = 4.0;
    const double baseArea = A * B;

    const double hVoltorb = 0.5;
    const double rVoltorb = hVoltorb / 2.0;
    const double volVoltorb = (4.0/3.0) * pi * rVoltorb * rVoltorb * rVoltorb;

    const double dPoke = 7.0 / 100.0;
    const double rPoke = dPoke / 2.0;
    const double volPoke = (4.0/3.0) * pi * rPoke * rPoke * rPoke;

    double totalVolume = V * volVoltorb + P * volPoke;
    double deltaH_m = totalVolume / baseArea;
    double deltaH_cm = deltaH_m * 100.0;

    cout.setf(std::ios::fixed);
    cout << "Altura da piscina aumentou: " << setprecision(1) << deltaH_cm << " cm";
    return 0;
}
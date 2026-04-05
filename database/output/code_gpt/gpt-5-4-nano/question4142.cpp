/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long double s;
    if (!(cin >> s)) return 0;

    long double v0 = 400.0L * 1000.0L / 3600.0L;
    long double a = -(v0 * v0) / (2.0L * s);

    cout.setf(std::ios::fixed);
    cout << setprecision(2) << "A desaceleracao desse veiculo foi de aproximadamente: " << (double)a << " m/s^2";
    return 0;
}
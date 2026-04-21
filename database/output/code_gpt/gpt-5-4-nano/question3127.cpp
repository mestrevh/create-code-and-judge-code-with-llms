/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long double theta_deg, v, g;
    if (!(cin >> theta_deg >> v >> g)) return 0;

    long double theta = theta_deg * acosl(-1.0L) / 180.0L;
    long double h = 0.0L;
    if (g != 0) h = (v * v * sinl(theta) * sinl(theta)) / (2.0L * g);

    cout << setprecision(15) << (double)h;
    return 0;
}
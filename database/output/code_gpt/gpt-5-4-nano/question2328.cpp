/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

double maiorCinco(double V, double W, double X, double Y, double Z) {
    double m = V;
    if (W > m) m = W;
    if (X > m) m = X;
    if (Y > m) m = Y;
    if (Z > m) m = Z;
    return m;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    double V, W, X, Y, Z;
    if (!(cin >> V)) return 0;
    cin >> W >> X >> Y >> Z;

    double ans = maiorCinco(V, W, X, Y, Z);
    cout << fixed << setprecision(2) << ans << "\n";
    return 0;
}
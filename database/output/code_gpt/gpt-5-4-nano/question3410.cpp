/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long double x, y;
    if (!(cin >> x >> y)) return 0;

    long double da = (x - 1) * (x - 1) + (y - 1) * (y - 1);
    long double db = (x - 2) * (x - 2) + (y - 1) * (y - 1);

    const long double eps = 1e-12L;

    bool inA = da <= 1.0L + eps;
    bool inB = db <= 1.0L + eps;

    if (inA && inB) cout << "Interior A,B";
    else if (inA) cout << "Interior A";
    else if (inB) cout << "Interior B";
    else cout << "Exterior";

    return 0;
}
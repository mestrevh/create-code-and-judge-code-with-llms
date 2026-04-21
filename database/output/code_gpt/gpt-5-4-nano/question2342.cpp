/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

void reduzir(double* x, double* y) {
    if (x && y) *x -= *y;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    double x, y;
    if (!(cin >> x >> y)) return 0;

    double* px = &x;
    double* py = &y;

    cout << fixed << setprecision(2) << *px << " " << *py << "\n";
    reduzir(px, py);
    cout << fixed << setprecision(2) << *px << " " << *py << "\n";

    return 0;
}
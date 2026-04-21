/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long double x;
    if (!(cin >> x)) return 0;

    long double floorx = floorl(x);
    long double ceilx = ceill(x);
    long double sqrtx = sqrtl(x);
    long double sinx = sinl(x);
    long double cosx = cosl(x);
    long double pow6 = powl(x, 6.0L);

    cout << fixed << setprecision(6);
    cout << (double)floorx << "\n";
    cout << (double)ceilx << "\n";
    cout << (double)sqrtx << "\n";
    cout << (double)sinx << "\n";
    cout << (double)cosx << "\n";
    cout << (double)pow6 << "\n";

    return 0;
}
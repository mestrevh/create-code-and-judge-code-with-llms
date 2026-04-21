/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long double ax, ay, az, bx, by, bz;
    if (!(cin >> ax >> ay >> az >> bx >> by >> bz)) return 0;

    long double dx = ax - bx;
    long double dy = ay - by;
    long double dz = az - bz;

    long double d = sqrtl(dx * dx + dy * dy + dz * dz);

    cout.setf(ios::fixed);
    cout << setprecision(16) << d << "\n";
    return 0;
}
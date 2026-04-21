/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long double x, y, t;
    cout.setf(std::ios::fixed);
    cout << setprecision(2);

    while (cin >> x >> y >> t) {
        long double rad = t * acosl(-1.0L) / 180.0L;
        long double nx = x * cosl(rad) - y * sinl(rad);
        long double ny = x * sinl(rad) + y * cosl(rad);

        const long double eps = 0.0000005L;
        if (fabsl(nx) < eps) nx = 0;
        if (fabsl(ny) < eps) ny = 0;

        cout << (double)nx << " " << (double)ny << "\n";
    }
    return 0;
}
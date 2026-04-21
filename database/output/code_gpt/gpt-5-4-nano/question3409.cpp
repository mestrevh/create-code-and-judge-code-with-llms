/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long double x, y, x1, y1, x2, y2;
    if (!(cin >> x >> y)) return 0;
    cin >> x1 >> y1;
    cin >> x2 >> y2;

    long double left = min(x1, x2), right = max(x1, x2);
    long double bottom = min(y1, y2), top = max(y1, y2);

    const long double eps = 1e-12L;
    if (x + eps >= left && x - eps <= right && y + eps >= bottom && y - eps <= top) {
        cout << "Dentro";
    } else {
        cout << "Fora";
    }
    return 0;
}
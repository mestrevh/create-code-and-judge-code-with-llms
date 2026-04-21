/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

struct Point {
    long double x, y;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long double x1, y1, x2, y2, x3, y3, x4, y4;
    cout.setf(std::ios::fixed);
    cout << setprecision(2);

    while (true) {
        if (!(cin >> x1 >> y1 >> x2 >> y2)) break;
        if (!(cin >> x3 >> y3 >> x4 >> y4)) break;

        Point a{ x1, y1 }, b{ x2, y2 }, c{ x3, y3 }, d{ x4, y4 };

        long double den = (a.x - b.x) * (c.y - d.y) - (a.y - b.y) * (c.x - d.x);

        if (fabsl(den) < 1e-18L) {
            cout << "NUNCA\n";
            continue;
        }

        long double det1 = a.x * b.y - a.y * b.x;
        long double det2 = c.x * d.y - c.y * d.x;

        long double px = (det1 * (c.x - d.x) - (a.x - b.x) * det2) / den;
        long double py = (det1 * (c.y - d.y) - (a.y - b.y) * det2) / den;

        cout << (double)px << " " << (double)py << "\n";
    }

    return 0;
}
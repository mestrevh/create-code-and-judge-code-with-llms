/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    double xp, yp;
    if (!(cin >> xp >> yp)) return 0;

    int n;
    cin >> n;

    int retCount = 0, cirCount = 0;

    for (int i = 0; i < n; i++) {
        string tipo;
        cin >> tipo;

        if (tipo == "retangulo") {
            double xmin, ymin, xmax, ymax;
            cin >> xmin >> ymin >> xmax >> ymax;
            double left = min(xmin, xmax), right = max(xmin, xmax);
            double bottom = min(ymin, ymax), top = max(ymin, ymax);
            if (xp >= left && xp <= right && yp >= bottom && yp <= top) retCount++;
        } else if (tipo == "circulo") {
            double xc, yc, r;
            cin >> xc >> yc >> r;
            r = fabs(r);
            double dx = xp - xc, dy = yp - yc;
            if (dx * dx + dy * dy <= r * r) cirCount++;
        }
    }

    cout << "Retangulos: " << retCount << "\n";
    cout << "Circulos: " << cirCount << "\n";
    return 0;
}
/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    double budget;
    if (!(cin >> budget)) return 0;

    double x, y, a, b, c, d;
    cin >> x >> y >> a >> b >> c >> d;

    double gas1, toll1, gas2, toll2;
    cin >> gas1 >> toll1;
    cin >> gas2 >> toll2;

    auto dist = [](double x1, double y1, double x2, double y2) {
        double dx = x1 - x2, dy = y1 - y2;
        return sqrt(dx * dx + dy * dy);
    };

    const double litersPerKm = 1.0 / 12.0;

    double d1 = dist(x, y, a, b);
    double d2 = dist(x, y, c, d);

    double needLiters1 = 2.0 * d1 * litersPerKm;
    double needLiters2 = 2.0 * d2 * litersPerKm;

    double cost1 = needLiters1 * gas1 + toll1;
    double cost2 = needLiters2 * gas2 + toll2;

    bool ok1 = cost1 <= budget + 1e-9;
    bool ok2 = cost2 <= budget + 1e-9;

    cout.setf(std::ios::fixed);
    cout << setprecision(2);

    if (ok1 && ok2) {
        cout << "Ele vai visitar os dois lugares\n";
        cout << (cost1 + cost2) + 0.0 << "\n";
    } else if (ok1 && !ok2) {
        cout << "Ele vai para o destino 1\n";
        cout << cost1 + 0.0 << "\n";
    } else if (!ok1 && ok2) {
        cout << "Ele vai para o destino 2\n";
        cout << cost2 + 0.0 << "\n";
    } else {
        cout << "Ele vai ficar em casa\n";
        cout << -1 << "\n";
    }

    return 0;
}
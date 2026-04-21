/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    double ax, ay, bx, by, cx, cy;
    if (!(cin >> ax)) return 0;
    cin >> ay >> bx >> by >> cx >> cy;

    auto dist = [](double x1, double y1, double x2, double y2) {
        double dx = x1 - x2, dy = y1 - y2;
        return sqrt(dx * dx + dy * dy);
    };

    double ab = dist(ax, ay, bx, by);
    double bc = dist(bx, by, cx, cy);
    double ca = dist(cx, cy, ax, ay);

    cout << fixed << setprecision(2);
    cout << "A-B: " << ab << "\n";
    cout << "B-C: " << bc << "\n";
    cout << "C-A: " << ca << "\n";

    return 0;
}
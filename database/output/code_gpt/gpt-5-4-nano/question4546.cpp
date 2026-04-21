/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

struct Point {
    double x, y;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    if (!(cin >> n)) return 0;
    vector<Point> p(n);
    for (int i = 0; i < n; i++) cin >> p[i].x >> p[i].y;

    int start = 0;
    for (int i = 1; i < n; i++) {
        if (p[i].x < p[start].x - 1e-12 ||
            (abs(p[i].x - p[start].x) <= 1e-12 && p[i].y < p[start].y)) {
            start = i;
        }
    }

    Point s = p[start];
    vector<Point> rest;
    rest.reserve(n - 1);
    for (int i = 0; i < n; i++) if (i != start) rest.push_back(p[i]);

    auto cross = [&](const Point& a, const Point& b, const Point& c) {
        double x1 = b.x - a.x, y1 = b.y - a.y;
        double x2 = c.x - a.x, y2 = c.y - a.y;
        return x1 * y2 - y1 * x2;
    };

    auto cmp = [&](const Point& a, const Point& b) {
        double ca = cross(s, a, b);
        if (abs(ca) > 1e-12) return ca > 0;
        double da = (a.x - s.x) * (a.x - s.x) + (a.y - s.y) * (a.y - s.y);
        double db = (b.x - s.x) * (b.x - s.x) + (b.y - s.y) * (b.y - s.y);
        return da < db;
    };

    sort(rest.begin(), rest.end(), cmp);

    cout.setf(std::ios::fixed);
    cout << setprecision(4);
    cout << s.x << " " << s.y << "\n";
    for (auto &pt : rest) {
        cout << pt.x << " " << pt.y << "\n";
    }
    return 0;
}
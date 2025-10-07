/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <cmath>
#include <iomanip>
#include <vector>

using namespace std;

struct Point {
    double x, y, z;
};

double sqr(double a) {
    return a * a;
}

double distancePointToTriangle(Point p, Point a, Point b, Point c) {
    Point ab = {b.x - a.x, b.y - a.y, b.z - a.z};
    Point ac = {c.x - a.x, c.y - a.y, c.z - a.z};
    Point ap = {p.x - a.x, p.y - a.y, p.z - a.z};

    double d1 = (ab.x * ap.x + ab.y * ap.y + ab.z * ap.z);
    double d2 = (ac.x * ap.x + ac.y * ap.y + ac.z * ap.z);
    if (d1 <= 0 && d2 <= 0) return sqrt(sqr(ap.x) + sqr(ap.y) + sqr(ap.z));

    Point bp = {p.x - b.x, p.y - b.y, p.z - b.z};
    double d3 = (ab.x * bp.x + ab.y * bp.y + ab.z * bp.z);
    double d4 = (ac.x * bp.x + ac.y * bp.y + ac.z * bp.z);
    if (d3 >= 0 && d4 <= d3) return sqrt(sqr(bp.x) + sqr(bp.y) + sqr(bp.z));

    double vc = d1 * d4 - d3 * d2;
    if (vc <= 0 && d1 >= 0 && d3 <= 0) return sqrt(sqr(ap.x) + sqr(ap.y) + sqr(ap.z));

    Point cp = {p.x - c.x, p.y - c.y, p.z - c.z};
    double d5 = (ab.x * cp.x + ab.y * cp.y + ab.z * cp.z);
    double d6 = (ac.x * cp.x + ac.y * cp.y + ac.z * cp.z);
    if (d6 >= 0 && d5 <= d6) return sqrt(sqr(cp.x) + sqr(cp.y) + sqr(cp.z));

    double vb = d1 * d6 - d5 * d2;
    if (vb <= 0 && d2 >= 0 && d6 <= 0) return sqrt(sqr(ap.x - (ab.x * (d1 / (d1 - d2 + d3))) +
        (ac.x * (d2 / (d1 - d2 + d3)))) + sqr(ap.y - (ab.y * (d1 / (d1 - d2 + d3))) +
        (ac.y * (d2 / (d1 - d2 + d3)))) + sqr(ap.z - (ab.z * (d1 / (d1 - d2 + d3))) +
        (ac.z * (d2 / (d1 - d2 + d3))))));

    double va = d5 * d6 - d3 * d4;
    if (va <= 0 && d4 >= 0 && d5 <= 0) return sqrt(sqr(ap.x - (ab.x * (d3 / (d3 - d4 + d5))) +
        (ac.x * (d4 / (d3 - d4 + d5)))) + sqr(ap.y - (ab.y * (d3 / (d3 - d4 + d5))) +
        (ac.y * (d4 / (d3 - d4 + d5)))) + sqr(ap.z - (ab.z * (d3 / (d3 - d4 + d5))) +
        (ac.z * (d4 / (d3 - d4 + d5))))));

    double denom = 1.0 / (sqr(d1) + sqr(d2) + sqr(d3));
    return sqrt(sqr(ap.x - (a.x + b.x + c.x) * denom) + 
                sqr(ap.y - (a.y + b.y + c.y) * denom) + 
                sqr(ap.z - (a.z + b.z + c.z) * denom));
}

double distanceBetweenTetrahedra(vector<Point> &r, vector<Point> &e) {
    double minDistance = 1e9;
    for (auto &ra : r)
        for (int i = 0; i < 4; ++i) minDistance = min(minDistance, distancePointToTriangle(ra, e[i], e[(i+1)%4], e[(i+2)%4]));
    for (auto &ea : e)
        for (int i = 0; i < 4; ++i) minDistance = min(minDistance, distancePointToTriangle(ea, r[i], r[(i+1)%4], r[(i+2)%4]));
    return minDistance;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        vector<Point> rebel(4), empire(4);
        for (auto &v : rebel) cin >> v.x >> v.y >> v.z;
        for (auto &v : empire) cin >> v.x >> v.y >> v.z;
        double distance = distanceBetweenTetrahedra(rebel, empire);
        cout << fixed << setprecision(2) << distance << endl;
    }
    return 0;
}

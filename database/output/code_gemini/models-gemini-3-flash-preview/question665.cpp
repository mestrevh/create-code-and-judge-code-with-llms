/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <iomanip>
#include <random>

using namespace std;

struct Point {
    double x, y;
};

struct Circle {
    Point c;
    double rSq;
};

double distSq(Point a, Point b) {
    return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}

Circle get_circle_3(Point A, Point B, Point C) {
    double x1 = A.x, y1 = A.y, x2 = B.x, y2 = B.y, x3 = C.x, y3 = C.y;
    double den = 2 * (x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2));
    if (abs(den) < 1e-9) {
        double d12 = distSq(A, B), d13 = distSq(A, C), d23 = distSq(B, C);
        if (d12 >= d13 && d12 >= d23) return {{(A.x + B.x) / 2.0, (A.y + B.y) / 2.0}, d12 / 4.0};
        if (d13 >= d12 && d13 >= d23) return {{(A.x + C.x) / 2.0, (A.y + C.y) / 2.0}, d13 / 4.0};
        return {{(B.x + C.x) / 2.0, (B.y + C.y) / 2.0}, d23 / 4.0};
    }
    double ux = ((x1 * x1 + y1 * y1) * (y2 - y3) + (x2 * x2 + y2 * y2) * (y3 - y1) + (x3 * x3 + y3 * y3) * (y1 - y2)) / den;
    double uy = ((x1 * x1 + y1 * y1) * (x3 - x2) + (x2 * x2 + y2 * y2) * (x1 - x3) + (x3 * x3 + y3 * y3) * (x2 - x1)) / den;
    Point center = {ux, uy};
    return {center, distSq(center, A)};
}

mt19937 rng(42);

Circle min_disk(vector<Point> P) {
    if (P.empty()) return {{0, 0}, 0};
    if (P.size() == 1) return {P[0], 0};
    if (P.size() > 2) shuffle(P.begin(), P.end(), rng);
    Circle D = {{(P[0].x + P[1].x) / 2.0, (P[0].y + P[1].y) / 2.0}, distSq(P[0], P[1]) / 4.0};
    for (int i = 2; i < (int)P.size(); i++) {
        if (distSq(P[i], D.c) > D.rSq + 1e-7) {
            D = {P[i], 0};
            for (int j = 0; j < i; j++) {
                if (distSq(P[j], D.c) > D.rSq + 1e-7) {
                    D = {{(P[i].x + P[j].x) / 2.0, (P[i].y + P[j].y) / 2.0}, distSq(P[i], P[j]) / 4.0};
                    for (int k = 0; k < j; k++) {
                        if (distSq(P[k], D.c) > D.rSq + 1e-7) {
                            D = get_circle_3(P[i], P[j], P[k]);
                        }
                    }
                }
            }
        }
    }
    return D;
}

void solve() {
    int N;
    while (cin >> N && N != 0) {
        vector<Point> pts(N);
        for (int i = 0; i < N; i++) {
            cin >> pts[i].x >> pts[i].y;
        }

        double min_max_rSq = min_disk(pts).rSq;

        for (int i = 0; i < N; i++) {
            for (int j = i + 1; j < N; j++) {
                vector<Point> s1, s2, sz;
                for (int k = 0; k < N; k++) {
                    double cp = (pts[j].x - pts[i].x) * (pts[k].y - pts[i].y) - (pts[j].y - pts[i].y) * (pts[k].x - pts[i].x);
                    if (cp > 1e-7) s1.push_back(pts[k]);
                    else if (cp < -1e-7) s2.push_back(pts[k]);
                    else sz.push_back(pts[k]);
                }
                sort(sz.begin(), sz.end(), [](const Point& a, const Point& b) {
                    if (abs(a.x - b.x) > 1e-7) return a.x < b.x;
                    return a.y < b.y;
                });
                for (int m = 0; m <= (int)sz.size(); m++) {
                    vector<Point> cur_s1 = s1, cur_s2 = s2;
                    for (int k = 0; k < m; k++) cur_s1.push_back(sz[k]);
                    for (int k = m; k < (int)sz.size(); k++) cur_s2.push_back(sz[k]);
                    
                    double r1 = min_disk(cur_s1).rSq;
                    if (r1 < min_max_rSq) {
                        double r2 = min_disk(cur_s2).rSq;
                        min_max_rSq = min(min_max_rSq, max(r1, r2));
                    }
                }
            }
        }
        cout << fixed << setprecision(2) << sqrt(min_max_rSq) << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}
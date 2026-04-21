/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>

using namespace std;

struct Point {
    double x, y;
};

inline double distSq(const Point& a, const Point& b) {
    return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}

Point getClosestOnSegment(const Point& m, const Point& a, const Point& b) {
    double dx = b.x - a.x;
    double dy = b.y - a.y;
    double lenSq = dx * dx + dy * dy;
    if (lenSq < 1e-15) return a;
    double t = ((m.x - a.x) * dx + (m.y - a.y) * dy) / lenSq;
    if (t < 0.0) return a;
    if (t > 1.0) return b;
    return {a.x + t * dx, a.y + t * dy};
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    double xm, ym;
    while (cin >> xm >> ym) {
        int n;
        if (!(cin >> n)) break;
        
        vector<Point> pts(n + 1);
        for (int i = 0; i <= n; ++i) {
            if (!(cin >> pts[i].x >> pts[i].y)) break;
        }
        
        Point m = {xm, ym};
        Point bestP = pts[0];
        double minD2 = -1.0;
        
        for (int i = 0; i < n; ++i) {
            Point p = getClosestOnSegment(m, pts[i], pts[i+1]);
            double d2 = distSq(m, p);
            if (minD2 < 0 || d2 < minD2) {
                minD2 = d2;
                bestP = p;
            }
        }
        
        cout << fixed << setprecision(4) << bestP.x << "\n" << bestP.y << "\n";
    }
    
    return 0;
}
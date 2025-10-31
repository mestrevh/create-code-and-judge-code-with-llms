/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath>
#include <limits>

struct Point {
    double x, y;
};

double distToSegment(Point p, Point a, Point b) {
    double apx = p.x - a.x;
    double apy = p.y - a.y;
    double bpx = p.x - b.x;
    double bpy = p.y - b.y;
    double abx = b.x - a.x;
    double aby = b.y - a.y;
    
    double ab2 = abx * abx + aby * aby;
    double ap_ab = apx * abx + apy * aby;
    double bp_ab = bpx * abx + bpy * aby;
    
    if (ap_ab < 0) return std::sqrt(apx * apx + apy * apy);
    if (bp_ab > 0) return std::sqrt(bpx * bpx + bpy * bpy);
    
    double r = ap_ab / ab2;
    Point proj = { a.x + r * abx, a.y + r * aby };
    return std::sqrt((proj.x - p.x) * (proj.x - p.x) + (proj.y - p.y) * (proj.y - p.y));
}

Point closestPointOnSegment(Point p, Point a, Point b) {
    double apx = p.x - a.x;
    double apy = p.y - a.y;
    double abx = b.x - a.x;
    double aby = b.y - a.y;

    double ab2 = abx * abx + aby * aby;
    double ap_ab = apx * abx + apy * aby;

    double r = ap_ab / ab2;
    if (r < 0) return a;
    if (r > 1) return b;
    return { a.x + r * abx, a.y + r * aby };
}

int main() {
    double Xm, Ym;
    while (std::cin >> Xm >> Ym) {
        int N;
        std::cin >> N;
        
        std::vector<Point> points;
        for (int i = 0; i < N; ++i) {
            Point a, b;
            std::cin >> a.x >> a.y >> b.x >> b.y;
            points.push_back(a);
            points.push_back(b);
        }
        
        double minDist = std::numeric_limits<double>::max();
        Point closestPoint;
        
        for (int i = 0; i < N; ++i) {
            Point a = points[2 * i];
            Point b = points[2 * i + 1];
            Point p = closestPointOnSegment({ Xm, Ym }, a, b);
            double dist = distToSegment({ Xm, Ym }, a, b);
            if (dist < minDist) {
                minDist = dist;
                closestPoint = p;
            }
        }

        std::cout << std::fixed << std::setprecision(4) << closestPoint.x << "\n";
        std::cout << std::fixed << std::setprecision(4) << closestPoint.y << "\n";
    }
    return 0;
}

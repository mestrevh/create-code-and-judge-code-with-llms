/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <cmath>

struct Point {
    double x, y;
};

double cross_product(Point p, Point q, Point r) {
    return (q.x - p.x) * (r.y - p.y) - (q.y - p.y) * (r.x - p.x);
}

double distSq(Point p1, Point p2) {
    return (p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y);
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;

    if (n <= 0) {
        return 0;
    }

    std::vector<Point> points(n);
    int min_idx = 0;
    for (int i = 0; i < n; ++i) {
        std::cin >> points[i].x >> points[i].y;
        if (points[i].x < points[min_idx].x) {
            min_idx = i;
        } else if (points[i].x == points[min_idx].x && points[i].y < points[min_idx].y) {
            min_idx = i;
        }
    }

    Point p0 = points[min_idx];
    std::swap(points[0], points[min_idx]);

    std::sort(points.begin() + 1, points.end(), [p0](const Point& a, const Point& b) {
        double orientation = cross_product(p0, a, b);

        if (std::fabs(orientation) < 1e-9) {
            return distSq(p0, a) < distSq(p0, b);
        }
        
        return orientation > 0;
    });

    std::cout << std::fixed << std::setprecision(4);
    for (const auto& p : points) {
        std::cout << p.x << " " << p.y << "\n";
    }

    return 0;
}

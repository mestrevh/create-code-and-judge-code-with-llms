/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath>
#include <set>
#include <algorithm>

struct Point {
    double x;
    double y;

    bool operator<(const Point& other) const {
        if (x < other.x - 1e-9) return true;
        if (x > other.x + 1e-9) return false;
        if (y < other.y - 1e-9) return true;
        if (y > other.y + 1e-9) return false;
        return false;
    }
};

double cross_product(Point p1, Point p2, Point p3) {
    return (p2.x - p1.x) * (p3.y - p1.y) - (p2.y - p1.y) * (p3.x - p1.x);
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;

    std::vector<Point> points(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> points[i].x >> points[i].y;
    }

    std::set<Point> hull_points;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i == j) {
                continue;
            }

            bool all_on_one_side = true;
            int first_sign = 0;

            for (int k = 0; k < n; ++k) {
                if (k == i || k == j) {
                    continue;
                }

                double cp = cross_product(points[i], points[j], points[k]);
                
                int current_sign = (cp > 0) ? 1 : -1;

                if (first_sign == 0) {
                    first_sign = current_sign;
                } else if (first_sign != current_sign) {
                    all_on_one_side = false;
                    break;
                }
            }

            if (all_on_one_side) {
                hull_points.insert(points[i]);
                hull_points.insert(points[j]);
            }
        }
    }

    std::cout << std::fixed << std::setprecision(4);

    for (const auto& p : hull_points) {
        std::cout << p.x << " " << p.y << "\n";
    }

    return 0;
}

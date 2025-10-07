/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
#include <cfloat>

struct Point {
    double x, y;
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::cout << std::fixed << std::setprecision(4);

    double mx, my;
    int n;

    while (std::cin >> mx) {
        std::cin >> my;
        std::cin >> n;

        Point m = {mx, my};
        std::vector<Point> rail_points(n + 1);
        for (int i = 0; i <= n; ++i) {
            std::cin >> rail_points[i].x;
            std::cin >> rail_points[i].y;
        }

        Point best_point;
        double min_dist_sq = DBL_MAX;

        for (int i = 0; i < n; ++i) {
            Point a = rail_points[i];
            Point b = rail_points[i + 1];
            Point current_closest;

            double vx = b.x - a.x;
            double vy = b.y - a.y;

            double wx = m.x - a.x;
            double wy = m.y - a.y;

            double c1 = wx * vx + wy * vy;
            if (c1 <= 0) {
                current_closest = a;
            } else {
                double c2 = vx * vx + vy * vy;
                if (c2 <= c1) {
                    current_closest = b;
                } else {
                    double t = c1 / c2;
                    current_closest = {a.x + t * vx, a.y + t * vy};
                }
            }

            double dist_sq = (m.x - current_closest.x) * (m.x - current_closest.x) +
                             (m.y - current_closest.y) * (m.y - current_closest.y);

            if (dist_sq < min_dist_sq) {
                min_dist_sq = dist_sq;
                best_point = current_closest;
            }
        }

        std::cout << best_point.x << std::endl;
        std::cout << best_point.y << std::endl;
    }

    return 0;
}

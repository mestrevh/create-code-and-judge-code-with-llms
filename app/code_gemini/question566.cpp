/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <iomanip>
#include <limits>

struct Point {
    double x, y;
};

double distSq(const Point& p1, const Point& p2) {
    return (p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y);
}

bool compareX(const Point& a, const Point& b) {
    if (a.x != b.x) return a.x < b.x;
    return a.y < b.y;
}

bool compareY(const Point& a, const Point& b) {
    return a.y < b.y;
}

double bruteForce(const std::vector<Point>& points, int left, int right) {
    double min_d_sq = std::numeric_limits<double>::max();
    for (int i = left; i <= right; ++i) {
        for (int j = i + 1; j <= right; ++j) {
            min_d_sq = std::min(min_d_sq, distSq(points[i], points[j]));
        }
    }
    return min_d_sq;
}

double closestUtil(std::vector<Point>& pointsX, int left, int right) {
    if (right - left < 3) {
        return bruteForce(pointsX, left, right);
    }

    int mid = left + (right - left) / 2;
    Point midPoint = pointsX[mid];

    double dl_sq = closestUtil(pointsX, left, mid);
    double dr_sq = closestUtil(pointsX, mid + 1, right);
    double d_sq = std::min(dl_sq, dr_sq);

    std::vector<Point> strip;
    for (int i = left; i <= right; ++i) {
        if ((pointsX[i].x - midPoint.x) * (pointsX[i].x - midPoint.x) < d_sq) {
            strip.push_back(pointsX[i]);
        }
    }

    std::sort(strip.begin(), strip.end(), compareY);

    for (size_t i = 0; i < strip.size(); ++i) {
        for (size_t j = i + 1; j < strip.size() && (strip[j].y - strip[i].y) * (strip[j].y - strip[i].y) < d_sq; ++j) {
            d_sq = std::min(d_sq, distSq(strip[i], strip[j]));
        }
    }

    return d_sq;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    while (std::cin >> n && n != 0) {
        if (n < 2) {
            if (n == 1) {
                double x, y;
                std::cin >> x >> y;
            }
            std::cout << "INFINITY\n";
            continue;
        }

        std::vector<Point> points(n);
        for (int i = 0; i < n; ++i) {
            std::cin >> points[i].x >> points[i].y;
        }

        std::sort(points.begin(), points.end(), compareX);

        double min_d_sq = closestUtil(points, 0, n - 1);
        double min_d = sqrt(min_d_sq);

        if (min_d >= 10000.0) {
            std::cout << "INFINITY\n";
        } else {
            std::cout << std::fixed << std::setprecision(4) << min_d << "\n";
        }
    }

    return 0;
}

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
    long long x, y;
};

long long dist_sq(Point p1, Point p2) {
    return (p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y);
}

bool compareX(const Point& a, const Point& b) {
    return a.x < b.x;
}

bool compareY(const Point& a, const Point& b) {
    return a.y < b.y;
}

long long brute_force(const std::vector<Point>& points, int left, int right) {
    long long min_d_sq = std::numeric_limits<long long>::max();
    for (int i = left; i <= right; ++i) {
        for (int j = i + 1; j <= right; ++j) {
            min_d_sq = std::min(min_d_sq, dist_sq(points[i], points[j]));
        }
    }
    return min_d_sq;
}

long long closest_pair_util(std::vector<Point>& points, int left, int right) {
    if (right - left <= 2) {
        return brute_force(points, left, right);
    }

    int mid = left + (right - left) / 2;
    Point mid_point = points[mid];

    long long d_sq = std::min(closest_pair_util(points, left, mid), closest_pair_util(points, mid + 1, right));

    std::vector<Point> strip;
    for (int i = left; i <= right; ++i) {
        if ((points[i].x - mid_point.x) * (points[i].x - mid_point.x) < d_sq) {
            strip.push_back(points[i]);
        }
    }

    std::sort(strip.begin(), strip.end(), compareY);

    for (size_t i = 0; i < strip.size(); ++i) {
        for (size_t j = i + 1; j < strip.size() && (strip[j].y - strip[i].y) * (strip[j].y - strip[i].y) < d_sq; ++j) {
            d_sq = std::min(d_sq, dist_sq(strip[i], strip[j]));
        }
    }

    return d_sq;
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

    std::sort(points.begin(), points.end(), compareX);

    long long result_sq = closest_pair_util(points, 0, n - 1);

    double result = std::sqrt(static_cast<double>(result_sq));

    std::cout << std::fixed << std::setprecision(4) << result << std::endl;

    return 0;
}

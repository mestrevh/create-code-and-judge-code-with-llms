/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <iomanip>
#include <random>

const double EPS = 1e-9;

struct Point {
    double x, y;
};

struct Circle {
    Point center;
    double radius_sq;
};

std::vector<Point> g_welzl_points;

double distSq(Point p1, Point p2) {
    return (p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y);
}

Circle circle_from_one(const Point& p1) {
    return {p1, 0};
}

Circle circle_from_two(const Point& p1, const Point& p2) {
    Point center = {(p1.x + p2.x) / 2.0, (p1.y + p2.y) / 2.0};
    double radius_sq = distSq(p1, center);
    return {center, radius_sq};
}

Circle circle_from_three(const Point& p1, const Point& p2, const Point& p3) {
    double D = 2.0 * (p1.x * (p2.y - p3.y) + p2.x * (p3.y - p1.y) + p3.x * (p1.y - p2.y));
    if (std::abs(D) < EPS) {
        double d12_sq = distSq(p1, p2), d13_sq = distSq(p1, p3), d23_sq = distSq(p2, p3);
        if (d12_sq >= d13_sq && d12_sq >= d23_sq) return circle_from_two(p1, p2);
        if (d13_sq >= d12_sq && d13_sq >= d23_sq) return circle_from_two(p1, p3);
        return circle_from_two(p2, p3);
    }
    Point center;
    center.x = ((p1.x * p1.x + p1.y * p1.y) * (p2.y - p3.y) + (p2.x * p2.x + p2.y * p2.y) * (p3.y - p1.y) + (p3.x * p3.x + p3.y * p3.y) * (p1.y - p2.y)) / D;
    center.y = ((p1.x * p1.x + p1.y * p1.y) * (p3.x - p2.x) + (p2.x * p2.x + p2.y * p2.y) * (p1.x - p3.x) + (p3.x * p3.x + p3.y * p3.y) * (p2.x - p1.x)) / D;
    return {center, distSq(p1, center)};
}

Circle trivial_mec(const std::vector<Point>& boundary) {
    if (boundary.empty()) return {{0, 0}, 0};
    if (boundary.size() == 1) return circle_from_one(boundary[0]);
    if (boundary.size() == 2) return circle_from_two(boundary[0], boundary[1]);
    return circle_from_three(boundary[0], boundary[1], boundary[2]);
}

Circle welzl_recursive(int n, std::vector<Point> boundary) {
    if (n == 0 || boundary.size() == 3) {
        return trivial_mec(boundary);
    }
    
    Point p = g_welzl_points[n - 1];
    Circle mec = welzl_recursive(n - 1, boundary);
    
    if (distSq(mec.center, p) < mec.radius_sq + EPS) {
        return mec;
    }
    
    boundary.push_back(p);
    return welzl_recursive(n - 1, boundary);
}

Circle welzl(const std::vector<Point>& points_to_cover) {
    if (points_to_cover.empty()) {
        return {{0,0}, 0};
    }
    g_welzl_points = points_to_cover;
    static std::mt19937 g(std::random_device{}());
    std::shuffle(g_welzl_points.begin(), g_welzl_points.end(), g);
    return welzl_recursive(g_welzl_points.size(), {});
}

bool check(double R, const std::vector<Point>& points) {
    double R_sq = R * R;
    int N = points.size();

    if (welzl(points).radius_sq <= R_sq + EPS) {
        return true;
    }

    for (int i = 0; i < N; ++i) {
        for (int j = i + 1; j < N; ++j) {
            double d_sq = distSq(points[i], points[j]);
            if (d_sq > 4 * R_sq + EPS) continue;

            double d = std::sqrt(d_sq);
            double h = std::sqrt(std::max(0.0, R_sq - d_sq / 4.0));
            
            Point mid = {(points[i].x + points[j].x) / 2.0, (points[i].y + points[j].y) / 2.0};
            Point v = {points[j].x - points[i].x, points[j].y - points[i].y};

            Point c1, c2;

            if (d > EPS) {
                c1 = {mid.x + h * v.y / d, mid.y - h * v.x / d};
                c2 = {mid.x - h * v.y / d, mid.y + h * v.x / d};
            } else {
                c1 = mid;
                c2 = mid;
            }

            std::vector<Point> uncovered;
            for (const auto& p : points) {
                if (distSq(c1, p) > R_sq + EPS) {
                    uncovered.push_back(p);
                }
            }
            if (uncovered.empty() || welzl(uncovered).radius_sq <= R_sq + EPS) {
                return true;
            }

            if (d > EPS) {
                uncovered.clear();
                for (const auto& p : points) {
                    if (distSq(c2, p) > R_sq + EPS) {
                        uncovered.push_back(p);
                    }
                }
                if (uncovered.empty() || welzl(uncovered).radius_sq <= R_sq + EPS) {
                    return true;
                }
            }
        }
    }

    return false;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int N;
    while (std::cin >> N && N != 0) {
        std::vector<Point> points(N);
        for (int i = 0; i < N; ++i) {
            std::cin >> points[i].x >> points[i].y;
        }

        double low = 0.0, high = 15000.0;
        for (int iter = 0; iter < 100; ++iter) {
            double mid = (low + high) / 2.0;
            if (check(mid, points)) {
                high = mid;
            } else {
                low = mid;
            }
        }
        std::cout << std::fixed << std::setprecision(2) << high << std::endl;
    }

    return 0;
}

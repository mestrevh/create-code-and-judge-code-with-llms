/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm>

struct Point {
    long long x, y;
};

bool comparePoints(const Point& a, const Point& b) {
    if (a.x != b.x) return a.x < b.x;
    return a.y < b.y;
}

bool areEqual(const Point& a, const Point& b) {
    return a.x == b.x && a.y == b.y;
}

long long cross_product(Point a, Point b, Point c) {
    return (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int N;
    int case_num = 0;
    
    while (std::cin >> N) {
        std::vector<Point> points(N);
        for (int i = 0; i < N; ++i) {
            std::cin >> points[i].x >> points[i].y;
        }
        
        std::cout << "caso " << case_num << ":\n";

        if (N > 0) {
            std::sort(points.begin(), points.end(), comparePoints);
            points.erase(std::unique(points.begin(), points.end(), areEqual), points.end());
            N = points.size();

            if (N <= 2) {
                int start_idx = 0;
                if (N == 2) {
                    if (points[1].y < points[0].y || (points[1].y == points[0].y && points[1].x < points[0].x)) {
                       start_idx = 1;
                    }
                }
                for (int i = 0; i < N; ++i) {
                    int current_idx = (start_idx + i) % N;
                    std::cout << points[current_idx].x << " " << points[current_idx].y << "\n";
                }
            } else {
                std::vector<Point> hull;
                
                for (int i = 0; i < N; ++i) {
                    while (hull.size() >= 2 && cross_product(hull[hull.size()-2], hull.back(), points[i]) <= 0) {
                        hull.pop_back();
                    }
                    hull.push_back(points[i]);
                }
                
                size_t lower_hull_size = hull.size();
                for (int i = N - 2; i >= 0; --i) {
                    while (hull.size() > lower_hull_size && cross_product(hull[hull.size()-2], hull.back(), points[i]) <= 0) {
                        hull.pop_back();
                    }
                    hull.push_back(points[i]);
                }
                
                hull.pop_back();

                int start_idx = 0;
                for (size_t i = 1; i < hull.size(); ++i) {
                    if (hull[i].y < hull[start_idx].y || (hull[i].y == hull[start_idx].y && hull[i].x < hull[start_idx].x)) {
                        start_idx = i;
                    }
                }
                
                for (size_t i = 0; i < hull.size(); ++i) {
                    int current_idx = (start_idx + i) % hull.size();
                    std::cout << hull[current_idx].x << " " << hull[current_idx].y << "\n";
                }
            }
        }
        
        std::cout << "\n";
        case_num++;
    }

    return 0;
}

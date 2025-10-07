/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iomanip>

struct Point {
    int x, y;
};

void solve() {
    int n;
    std::cin >> n;
    std::vector<Point> points(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> points[i].x >> points[i].y;
    }

    std::sort(points.begin(), points.end(), [](const Point& a, const Point& b) {
        return a.x < b.x;
    });

    double total_sunny_length = 0.0;
    
    if (n > 1) {
        double max_y_on_right = static_cast<double>(points.back().y);

        for (int i = n - 2; i >= 0; --i) {
            if (static_cast<double>(points[i].y) > max_y_on_right) {
                double dx_total = static_cast<double>(points[i + 1].x - points[i].x);
                double dy_total_abs = static_cast<double>(points[i].y - points[i + 1].y);
                
                double segment_len = std::sqrt(dx_total * dx_total + dy_total_abs * dy_total_abs);

                double dy_sunny = static_cast<double>(points[i].y) - max_y_on_right;
                
                if (dy_total_abs > 1e-9) {
                    double sunny_len = segment_len * dy_sunny / dy_total_abs;
                    total_sunny_length += sunny_len;
                }
            }
            max_y_on_right = std::max(max_y_on_right, static_cast<double>(points[i].y));
        }
    }

    std::cout << std::fixed << std::setprecision(2) << total_sunny_length << std::endl;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int c;
    std::cin >> c;
    while (c--) {
        solve();
    }

    return 0;
}

/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <stdexcept>

struct Point {
    long double x, y;
    std::string original_string;
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::string line;
    std::getline(std::cin, line);

    std::vector<Point> points;
    size_t current_pos = 0;
    while ((current_pos = line.find('*', current_pos)) != std::string::npos) {
        size_t next_pos = line.find('*', current_pos + 1);
        
        std::string point_str_with_star;
        if (next_pos == std::string::npos) {
            point_str_with_star = line.substr(current_pos);
            current_pos = line.length(); 
        } else {
            point_str_with_star = line.substr(current_pos, next_pos - current_pos);
            current_pos = next_pos;
        }

        if (point_str_with_star.length() <= 1) {
            continue;
        }

        std::string coords_str = point_str_with_star.substr(1);
        size_t comma_pos = coords_str.find(',');
        if (comma_pos == std::string::npos) {
            continue;
        }
        
        std::string x_str = coords_str.substr(0, comma_pos);
        std::string y_str = coords_str.substr(comma_pos + 1);

        try {
            long double x = std::stold(x_str);
            long double y = std::stold(y_str);
            points.push_back({x, y, point_str_with_star});
        } catch (const std::exception& e) {
            // Ignore parsing errors
        }
    }

    if (points.empty()) {
        std::cout << std::endl;
        return 0;
    }

    int pivot_idx = 0;
    for (size_t i = 1; i < points.size(); ++i) {
        if (points[i].x > points[pivot_idx].x) {
            pivot_idx = i;
        } else if (std::abs(points[i].x - points[pivot_idx].x) < 1e-12) {
            if (points[i].y < points[pivot_idx].y) {
                pivot_idx = i;
            }
        }
    }

    std::swap(points[0], points[pivot_idx]);
    Point pivot = points[0];

    std::sort(points.begin() + 1, points.end(), [&](const Point& a, const Point& b) {
        long double dx_a = a.x - pivot.x;
        long double dy_a = a.y - pivot.y;
        long double dx_b = b.x - pivot.x;
        long double dy_b = b.y - pivot.y;

        long double cross_product = dx_a * dy_b - dy_a * dx_b;
        
        if (std::abs(cross_product) < 1e-12) { 
            long double dist_sq_a = dx_a * dx_a + dy_a * dy_a;
            long double dist_sq_b = dx_b * dx_b + dy_b * dy_b;
            return dist_sq_a < dist_sq_b;
        }
        
        return cross_product > 0;
    });

    for (const auto& p : points) {
        std::cout << p.original_string;
    }
    std::cout << std::endl;

    return 0;
}

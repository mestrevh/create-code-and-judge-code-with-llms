/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <iomanip>

struct Point {
    double x, y;
    std::string original;

    Point(double x, double y, std::string original) : x(x), y(y), original(original) {}
};

bool compare(Point& a, Point& b) {
    return a.x < b.x;
}

double cross_product(Point& a, Point& b, Point& origin) {
    return (b.x - origin.x) * (a.y - origin.y) - (a.x - origin.x) * (b.y - origin.y);
}

int main() {
    std::string line;
    std::vector<Point> points;

    while (std::getline(std::cin, line)) {
        std::istringstream iss(line);
        while (true) {
            std::string segment;
            if (!std::getline(iss, segment, '*')) break;

            double x, y;
            if (sscanf(segment.c_str(), "%lf, %lf", &x, &y) == 2) {
                points.emplace_back(x, y, segment);
            }
        }
    }

    std::sort(points.begin(), points.end(), compare);
    Point origin = points.back(); 

    std::sort(points.begin(), points.end(), [&](Point& a, Point& b) {
        double cp = cross_product(a, b, origin);
        return cp < 0 || (cp == 0 && a.x < b.x);
    });

    for (const auto& p : points) {
        std::cout << p.original;
    }
    std::cout << std::endl;

    return 0;
}

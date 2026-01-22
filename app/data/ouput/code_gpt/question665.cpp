/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath>
#include <limits>

using namespace std;

struct Point {
    double x, y;
};

double distance(const Point& a, const Point& b) {
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

double minRadius(const vector<Point>& points, const Point& tower1, const Point& tower2) {
    double maxDist = 0.0;
    for (const auto& point : points) {
        double dist1 = distance(point, tower1);
        double dist2 = distance(point, tower2);
        maxDist = max(maxDist, min(dist1, dist2));
    }
    return maxDist;
}

double computeMinCoverageRadius(vector<Point>& points) {
    double minRadius = numeric_limits<double>::max();
    int n = points.size();
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            double radius = minRadius(points, points[i], points[j]);
            minRadius = min(minRadius, radius);
        }
    }
    return minRadius;
}

int main() {
    while (true) {
        int n;
        cin >> n;
        if (n == 0) break;

        vector<Point> points(n);
        for (int i = 0; i < n; i++) {
            cin >> points[i].x >> points[i].y;
        }

        double radius = computeMinCoverageRadius(points);
        cout << fixed << setprecision(2) << radius << endl;
    }
    return 0;
}

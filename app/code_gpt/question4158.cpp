/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

struct Point {
    char name;
    double x, y;

    double distance(double x0, double y0) {
        return sqrt(pow(x - x0, 2) + pow(y - y0, 2));
    }
};

bool compare(const Point& p1, const Point& p2) {
    double dist1 = p1.distance(0, 0);
    double dist2 = p2.distance(0, 0);
    if (dist1 == dist2) return p1.name < p2.name;
    return dist1 < dist2;
}

int main() {
    double x, y;
    cin >> x >> y;

    vector<Point> points = {
        {'A', x + 1, y + 1}, // Lidar com A
        {'B', x - 2, y + 2}, // Lidar com B
        {'C', x + 2, y + 1}  // Lidar com C
    };

    sort(points.begin(), points.end(), compare);
    
    for (const auto& p : points) {
        cout << p.name << " ";
    }
    return 0;
}

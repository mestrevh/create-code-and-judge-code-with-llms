/*
Código criado pelo Gemini Pro 1.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iomanip>

using namespace std;

struct Point {
    double x, y;
};

double cross_product(Point a, Point b, Point c) {
    return (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
}

int main() {
    int n;
    cin >> n;

    vector<Point> points(n);
    for (int i = 0; i < n; ++i) {
        cin >> points[i].x >> points[i].y;
    }

    int start_index = 0;
    for (int i = 1; i < n; ++i) {
        if (points[i].x < points[start_index].x || (points[i].x == points[start_index].x && points[i].y < points[start_index].y)) {
            start_index = i;
        }
    }

    swap(points[0], points[start_index]);

    sort(points.begin() + 1, points.end(), [&](Point a, Point b) {
        double cp = cross_product(points[0], a, b);
        if (cp != 0) {
            return cp > 0;
        }
        return (a.x - points[0].x) * (a.x - points[0].x) + (a.y - points[0].y) * (a.y - points[0].y) <
               (b.x - points[0].x) * (b.x - points[0].x) + (b.y - points[0].y) * (b.y - points[0].y);
    });

    cout << fixed << setprecision(4);
    for (int i = 0; i < n; ++i) {
        cout << points[i].x << " " << points[i].y << endl;
    }

    return 0;
}

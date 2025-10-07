/*
Código criado pelo Gemini Pro 1.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <cmath>

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

    vector<Point> hull;
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            bool valid = true;
            double cp = 0;
            for (int k = 0; k < n; ++k) {
                if (k == i || k == j) continue;
                double current_cp = cross_product(points[i], points[j], points[k]);
                if (cp == 0) {
                    cp = current_cp;
                } else if (cp * current_cp < 0) {
                    valid = false;
                    break;
                }
            }
            if (valid) {
                hull.push_back(points[i]);
                hull.push_back(points[j]);
            }
        }
    }

    sort(hull.begin(), hull.end(), [](Point a, Point b) {
        if (a.x != b.x) {
            return a.x < b.x;
        }
        return a.y < b.y;
    });

    hull.erase(unique(hull.begin(), hull.end(), [](Point a, Point b) {
        return a.x == b.x && a.y == b.y;
    }), hull.end());


    for (const auto& p : hull) {
        cout << fixed << setprecision(4) << p.x << " " << p.y << endl;
    }

    return 0;
}

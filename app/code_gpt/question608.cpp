/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Point {
    int x, y;
};

bool compare(Point a, Point b) {
    if (a.y == b.y) return a.x < b.x;
    return a.y < b.y;
}

int orientation(Point p, Point q, Point r) {
    int val = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);
    if (val == 0) return 0; // colinear
    return (val > 0) ? 1 : 2; // clock or counter clock wise
}

vector<Point> convexHull(vector<Point>& points) {
    int n = points.size();
    if (n < 3) return {};

    vector<Point> hull;

    sort(points.begin(), points.end(), compare);
    
    Point p0 = points[0];
    hull.push_back(p0);

    for (int i = 1; i < n; i++) {
        while (hull.size() >= 2 && orientation(hull[hull.size() - 2], hull.back(), points[i]) != 2) {
            hull.pop_back();
        }
        hull.push_back(points[i]);
    }

    int t = hull.size() + 1;
    for (int i = n - 2; i >= 0; i--) {
        while (hull.size() >= t && orientation(hull[hull.size() - 2], hull.back(), points[i]) != 2) {
            hull.pop_back();
        }
        hull.push_back(points[i]);
    }
    hull.pop_back();

    return hull;
}

int main() {
    int caseNum = 0;
    while (true) {
        int N;
        cin >> N;
        if (N == 0) break;
        
        vector<Point> points(N);
        for (int i = 0; i < N; i++) {
            cin >> points[i].x >> points[i].y;
        }

        vector<Point> hull = convexHull(points);
        
        // Ensure the first point is the southernmost and westernmost
        sort(hull.begin(), hull.end(), [](Point a, Point b) {
            return a.y == b.y ? a.x < b.x : a.y < b.y;
        });

        cout << "caso " << caseNum++ << ":" << endl;
        for (const auto& p : hull) {
            cout << p.x << " " << p.y << endl;
        }
        cout << endl;
    }
    return 0;
}

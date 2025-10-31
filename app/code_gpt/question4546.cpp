/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

struct Point {
    double x, y;
};

bool compare(const Point &a, const Point &b) {
    return a.y < b.y || (a.y == b.y && a.x < b.x);
}

double cross(const Point &O, const Point &A, const Point &B) {
    return (A.x - O.x) * (B.y - O.y) - (A.y - O.y) * (B.x - O.x);
}

void sortPoints(vector<Point> &points) {
    Point pivot = *min_element(points.begin(), points.end(), compare);
    sort(points.begin(), points.end(), [pivot](const Point &a, const Point &b) {
        double c = cross(pivot, a, b);
        return c > 0 || (c == 0 && (a.x < b.x || (a.x == b.x && a.y < b.y)));
    });
}

int main() {
    int n;
    cin >> n;
    vector<Point> points(n);
    
    for (int i = 0; i < n; i++) {
        cin >> points[i].x >> points[i].y;
    }

    sortPoints(points);
    
    for (const auto &p : points) {
        cout << fixed << setprecision(4) << p.x << " " << p.y << endl;
    }
    
    return 0;
}

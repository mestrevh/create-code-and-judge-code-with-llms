/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>

using namespace std;

struct Point {
    double x, y;
};

bool intersect(Point p1, Point p2, Point p3, Point p4, Point &intersection) {
    double A1 = p2.y - p1.y;
    double B1 = p1.x - p2.x;
    double C1 = A1 * p1.x + B1 * p1.y;

    double A2 = p4.y - p3.y;
    double B2 = p3.x - p4.x;
    double C2 = A2 * p3.x + B2 * p3.y;

    double det = A1 * B2 - A2 * B1;
    if (det == 0) return false;

    intersection.x = (B2 * C1 - B1 * C2) / det;
    intersection.y = (A1 * C2 - A2 * C1) / det;

    return true;
}

bool onSegment(Point p, Point q, Point r) {
    return (p.x <= max(q.x, r.x) && p.x >= min(q.x, r.x) && p.y <= max(q.y, r.y) && p.y >= min(q.y, r.y));
}

bool isPointOnLineSegment(Point intersection, Point p1, Point p2) {
    return onSegment(intersection, p1, p2);
}

int main() {
    Point p1, p2, p3, p4, intersection;
    while (cin >> p1.x >> p1.y >> p2.x >> p2.y >> p3.x >> p3.y >> p4.x >> p4.y) {
        if (intersect(p1, p2, p3, p4, intersection)) {
            if (isPointOnLineSegment(intersection, p1, p2) && isPointOnLineSegment(intersection, p3, p4)) {
                cout << fixed << setprecision(2) << intersection.x << " " << intersection.y << endl;
            } else {
                cout << "NUNCA" << endl;
            }
        } else {
            cout << "NUNCA" << endl;
        }
    }
    return 0;
}

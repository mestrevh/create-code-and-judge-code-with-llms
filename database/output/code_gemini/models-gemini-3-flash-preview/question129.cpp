/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <iomanip>

using namespace std;

struct Point {
    double x, y, z;
    Point operator-(const Point& other) const { return {x - other.x, y - other.y, z - other.z}; }
    Point operator+(const Point& other) const { return {x + other.x, y + other.y, z + other.z}; }
    Point operator*(double k) const { return {x * k, y * k, z * k}; }
};

inline double dot(Point a, Point b) {
    return a.x * b.x + a.y * b.y + a.z * b.z;
}

inline Point cross(Point a, Point b) {
    return {a.y * b.z - a.z * b.y, a.z * b.x - a.x * b.z, a.x * b.y - a.y * b.x};
}

inline double norm(Point a) {
    return sqrt(dot(a, a));
}

double distPointSegment(Point p, Point a, Point b) {
    Point ab = b - a, ap = p - a, bp = p - b;
    double d1 = dot(ab, ap), d2 = dot(ab, bp);
    if (d1 <= 0) return norm(ap);
    if (d2 >= 0) return norm(bp);
    Point cp = cross(ab, ap);
    return norm(cp) / norm(ab);
}

double distSegmentSegment(Point p1, Point p2, Point q1, Point q2) {
    Point d1 = p2 - p1, d2 = q2 - q1, r = p1 - q1;
    double a = dot(d1, d1), e = dot(d2, d2), f = dot(d2, r);
    double b = dot(d1, d2), c = dot(d1, r);
    double det = a * e - b * b;
    double s = 0.0, t = 0.0;
    if (det > 1e-12) {
        s = max(0.0, min(1.0, (b * f - c * e) / det));
        t = (b * s + f) / e;
        if (t < 0.0) {
            t = 0.0;
            s = max(0.0, min(1.0, -c / a));
        } else if (t > 1.0) {
            t = 1.0;
            s = max(0.0, min(1.0, (b - c) / a));
        }
    } else {
        double d1_sq = distPointSegment(p1, q1, q2);
        double d2_sq = distPointSegment(p2, q1, q2);
        double d3_sq = distPointSegment(q1, p1, p2);
        double d4_sq = distPointSegment(q2, p1, p2);
        return min({d1_sq, d2_sq, d3_sq, d4_sq});
    }
    Point diff = p1 + (d1 * s) - (q1 + (d2 * t));
    return norm(diff);
}

double distPointTriangleInterior(Point p, Point a, Point b, Point c) {
    Point n = cross(b - a, c - a);
    double n2 = dot(n, n);
    if (n2 < 1e-15) return 1e18;
    double d = dot(p - a, n);
    Point q = p - (n * (d / n2));
    Point cp1 = cross(b - a, q - a);
    Point cp2 = cross(c - b, q - b);
    Point cp3 = cross(a - c, q - c);
    double dot1 = dot(cp1, n), dot2 = dot(cp2, n), dot3 = dot(cp3, n);
    if ((dot1 >= -1e-11 && dot2 >= -1e-11 && dot3 >= -1e-11) ||
        (dot1 <= 1e-11 && dot2 <= 1e-11 && dot3 <= 1e-11)) {
        return abs(d) / sqrt(n2);
    }
    return 1e18;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t_cases;
    if (!(cin >> t_cases)) return 0;

    while (t_cases--) {
        Point p[8];
        for (int i = 0; i < 8; ++i) {
            cin >> p[i].x >> p[i].y >> p[i].z;
        }

        double minDist = 1e18;

        int edgeIdx[6][2] = {{0, 1}, {0, 2}, {0, 3}, {1, 2}, {1, 3}, {2, 3}};
        for (int i = 0; i < 6; ++i) {
            for (int j = 0; j < 6; ++j) {
                minDist = min(minDist, distSegmentSegment(p[edgeIdx[i][0]], p[edgeIdx[i][1]], 
                                                         p[edgeIdx[j][0] + 4], p[edgeIdx[j][1] + 4]));
            }
        }

        int faceIdx[4][3] = {{0, 1, 2}, {0, 1, 3}, {0, 2, 3}, {1, 2, 3}};
        for (int i = 0; i < 4; ++i) {
            for (int j = 0; j < 4; ++j) {
                minDist = min(minDist, distPointTriangleInterior(p[i], p[faceIdx[j][0] + 4], 
                                                                p[faceIdx[j][1] + 4], p[faceIdx[j][2] + 4]));
            }
        }
        for (int i = 0; i < 4; ++i) {
            for (int j = 0; j < 4; ++j) {
                minDist = min(minDist, distPointTriangleInterior(p[i + 4], p[faceIdx[j][0]], 
                                                                p[faceIdx[j][1]], p[faceIdx[j][2]]));
            }
        }

        cout << fixed << setprecision(2) << minDist << "\n";
    }

    return 0;
}
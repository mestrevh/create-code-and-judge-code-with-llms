/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
#include <algorithm>
#include <limits>

const double INF = std::numeric_limits<double>::infinity();
const double EPS = 1e-9;

struct Point {
    double x, y, z;
};

Point operator+(const Point& a, const Point& b) { return {a.x + b.x, a.y + b.y, a.z + b.z}; }
Point operator-(const Point& a, const Point& b) { return {a.x - b.x, a.y - b.y, a.z - b.z}; }
Point operator*(double s, const Point& a) { return {s * a.x, s * a.y, s * a.z}; }
double dot(const Point& a, const Point& b) { return a.x * b.x + a.y * b.y + a.z * b.z; }
Point cross(const Point& a, const Point& b) {
    return {a.y * b.z - a.z * b.y, a.z * b.x - a.x * b.z, a.x * b.y - a.y * b.x};
}
double norm_sq(const Point& a) { return dot(a, a); }

struct Edge { Point p1, p2; };
struct Face { Point p1, p2, p3; };

double dist_point_segment_sq(const Point& p, const Point& a, const Point& b) {
    Point ab = b - a;
    Point ap = p - a;
    double len_sq_ab = norm_sq(ab);
    if (len_sq_ab < EPS) {
        return norm_sq(ap);
    }
    double t = dot(ap, ab) / len_sq_ab;
    t = std::max(0.0, std::min(1.0, t));
    Point projection = a + t * ab;
    return norm_sq(p - projection);
}

double dist_point_triangle_sq(const Point& p, const Point& a, const Point& b, const Point& c) {
    Point ab = b - a;
    Point ac = c - a;
    Point n = cross(ab, ac);
    double norm_n_sq = norm_sq(n);

    if (norm_n_sq < EPS) {
        return dist_point_segment_sq(p, a, b);
    }

    double t = dot(a - p, n) / norm_n_sq;
    Point q = p + t * n;

    Point aq = q - a;
    double d00 = dot(ab, ab);
    double d01 = dot(ab, ac);
    double d11 = dot(ac, ac);
    double d20 = dot(aq, ab);
    double d21 = dot(aq, ac);
    double denom = d00 * d11 - d01 * d01;
    
    if (std::abs(denom) < EPS) {
       return std::min({dist_point_segment_sq(p, a, b), dist_point_segment_sq(p, a, c)});
    }

    double u = (d11 * d20 - d01 * d21) / denom;
    double v = (d00 * d21 - d01 * d20) / denom;

    if (u >= -EPS && v >= -EPS && (u + v) <= 1.0 + EPS) {
        return norm_sq(p - q);
    } else {
        double d1_sq = dist_point_segment_sq(p, a, b);
        double d2_sq = dist_point_segment_sq(p, b, c);
        double d3_sq = dist_point_segment_sq(p, c, a);
        return std::min({d1_sq, d2_sq, d3_sq});
    }
}

double dist_segment_segment_sq(const Point& p1, const Point& q1, const Point& p2, const Point& q2) {
    Point u = q1 - p1;
    Point v = q2 - p2;
    Point w = p1 - p2;
    double a = dot(u, u);
    double b = dot(u, v);
    double c = dot(v, v);
    double d = dot(u, w);
    double e = dot(v, w);
    double D = a * c - b * b;
    double sc, sN, sD = D;
    double tc, tN, tD = D;

    if (D < EPS) {
        sN = 0.0;
        sD = 1.0;
        tN = e;
        tD = c;
    } else {
        sN = (b * e - c * d);
        tN = (a * e - b * d);
        if (sN < 0.0) {
            sN = 0.0;
            tN = e;
            tD = c;
        } else if (sN > sD) {
            sN = sD;
            tN = e + b;
            tD = c;
        }
    }

    if (tN < 0.0) {
        tN = 0.0;
        if (-d < 0.0) {
            sN = 0.0;
        } else if (-d > a) {
            sN = sD;
        } else {
            sN = -d;
            sD = a;
        }
    } else if (tN > tD) {
        tN = tD;
        if ((-d + b) < 0.0) {
            sN = 0;
        } else if ((-d + b) > a) {
            sN = sD;
        } else {
            sN = (-d + b);
            sD = a;
        }
    }

    sc = (std::abs(sN) < EPS ? 0.0 : sN / sD);
    tc = (std::abs(tN) < EPS ? 0.0 : tN / tD);

    Point dP = w + (sc * u) - (tc * v);
    return norm_sq(dP);
}

void solve() {
    std::vector<Point> vA(4), vB(4);
    for (int i = 0; i < 4; ++i) std::cin >> vA[i].x >> vA[i].y >> vA[i].z;
    for (int i = 0; i < 4; ++i) std::cin >> vB[i].x >> vB[i].y >> vB[i].z;

    std::vector<Edge> edgesA, edgesB;
    int indices[6][2] = {{0, 1}, {0, 2}, {0, 3}, {1, 2}, {1, 3}, {2, 3}};
    for (auto& idx : indices) {
        edgesA.push_back({vA[idx[0]], vA[idx[1]]});
        edgesB.push_back({vB[idx[0]], vB[idx[1]]});
    }

    std::vector<Face> facesA, facesB;
    int face_indices[4][3] = {{0, 1, 2}, {0, 1, 3}, {0, 2, 3}, {1, 2, 3}};
    for (auto& idx : face_indices) {
        facesA.push_back({vA[idx[0]], vA[idx[1]], vA[idx[2]]});
        facesB.push_back({vB[idx[0]], vB[idx[1]], vB[idx[2]]});
    }
    
    double min_dist_sq = INF;

    for (const auto& edgeA : edgesA) {
        for (const auto& edgeB : edgesB) {
            min_dist_sq = std::min(min_dist_sq, dist_segment_segment_sq(edgeA.p1, edgeA.p2, edgeB.p1, edgeB.p2));
        }
    }

    for (const auto& vertexA : vA) {
        for (const auto& faceB : facesB) {
            min_dist_sq = std::min(min_dist_sq, dist_point_triangle_sq(vertexA, faceB.p1, faceB.p2, faceB.p3));
        }
    }

    for (const auto& vertexB : vB) {
        for (const auto& faceA : facesA) {
            min_dist_sq = std::min(min_dist_sq, dist_point_triangle_sq(vertexB, faceA.p1, faceA.p2, faceA.p3));
        }
    }

    std::cout << std::fixed << std::setprecision(2) << sqrt(min_dist_sq) << std::endl;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int t;
    std::cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}

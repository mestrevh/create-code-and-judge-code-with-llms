/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
#include <algorithm>
#include <queue>

using namespace std;

struct Point {
    double x, y;
};

double dist(Point a, Point b) {
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

double cross_product(Point a, Point b, Point c) {
    return (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
}

const double eps = 1e-9;

bool intersectProper(Point a, Point b, Point c, Point d) {
    double cp1 = cross_product(a, b, c);
    double cp2 = cross_product(a, b, d);
    double cp3 = cross_product(c, d, a);
    double cp4 = cross_product(c, d, b);
    if (((cp1 > eps && cp2 < -eps) || (cp1 < -eps && cp2 > eps)) &&
        ((cp3 > eps && cp4 < -eps) || (cp3 < -eps && cp4 > eps))) return true;
    return false;
}

bool onSegment(Point p, Point a, Point b) {
    if (abs(cross_product(a, b, p)) > eps) return false;
    return p.x >= min(a.x, b.x) - eps && p.x <= max(a.x, b.x) + eps &&
           p.y >= min(a.y, b.y) - eps && p.y <= max(a.y, b.y) + eps;
}

bool onSegmentInterior(Point p, Point a, Point b) {
    if (abs(cross_product(a, b, p)) > eps) return false;
    return (p.x > min(a.x, b.x) + eps && p.x < max(a.x, b.x) - eps) ||
           (p.y > min(a.y, b.y) + eps && p.y < max(a.y, b.y) - eps);
}

bool isForbidden(Point p1, Point p2, Point a, Point b) {
    if (intersectProper(p1, p2, a, b)) return true;
    if (onSegmentInterior(p1, a, b)) return true;
    if (onSegmentInterior(p2, a, b)) return true;
    if (abs(cross_product(p1, p2, a)) < eps && abs(cross_product(p1, p2, b)) < eps) {
        Point mid = {(a.x + b.x) / 2.0, (a.y + b.y) / 2.0};
        if (onSegment(mid, p1, p2)) return true;
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    double xi, yi, xf, yf;
    int n;
    while (cin >> xi >> yi >> xf >> yf >> n && (xi != 0 || yi != 0 || xf != 0 || yf != 0 || n != 0)) {
        vector<Point> points;
        points.push_back({xi, yi});
        points.push_back({xf, yf});
        vector<pair<Point, Point>> obstacles(n);
        for (int i = 0; i < n; ++i) {
            cin >> obstacles[i].first.x >> obstacles[i].first.y >> obstacles[i].second.x >> obstacles[i].second.y;
            points.push_back(obstacles[i].first);
            points.push_back(obstacles[i].second);
        }

        int V = points.size();
        vector<vector<double>> adj(V, vector<double>(V, 1e18));

        for (int i = 0; i < V; ++i) {
            for (int j = i + 1; j < V; ++j) {
                bool ok = true;
                for (int k = 0; k < n; ++k) {
                    if (isForbidden(points[i], points[j], obstacles[k].first, obstacles[k].second)) {
                        ok = false;
                        break;
                    }
                }
                if (ok) {
                    double d = dist(points[i], points[j]);
                    adj[i][j] = adj[j][i] = d;
                }
            }
        }

        vector<double> min_d(V, 1e18);
        min_d[0] = 0;
        priority_queue<pair<double, int>, vector<pair<double, int>>, greater<pair<double, int>>> pq;
        pq.push({0, 0});

        while (!pq.empty()) {
            double d = pq.top().first;
            int u = pq.top().second;
            pq.pop();

            if (d > min_d[u] + eps) continue;
            if (u == 1) break;

            for (int v = 0; v < V; v++) {
                if (adj[u][v] < 1e17) {
                    if (min_d[v] > min_d[u] + adj[u][v]) {
                        min_d[v] = min_d[u] + adj[u][v];
                        pq.push({min_d[v], v});
                    }
                }
            }
        }

        cout << fixed << setprecision(2) << min_d[1] << "\n";
    }

    return 0;
}


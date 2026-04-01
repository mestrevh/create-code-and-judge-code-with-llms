/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
#include <queue>
#include <algorithm>

using namespace std;

struct Point {
    double x, y;
};

struct Mural {
    Point p1, p2;
};

double distSq(Point a, Point b) {
    return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}

double dist(Point a, Point b) {
    return sqrt(distSq(a, b));
}

double cross_product(Point a, Point b, Point c) {
    return (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
}

double dot_product(Point p, Point a, Point b) {
    return (a.x - p.x) * (b.x - p.x) + (a.y - p.y) * (b.y - p.y);
}

bool isSame(Point a, Point b) {
    return abs(a.x - b.x) < 1e-9 && abs(a.y - b.y) < 1e-9;
}

bool onSegment(Point p, Point a, Point b) {
    return abs(cross_product(a, b, p)) < 1e-9 && dot_product(p, a, b) <= 1e-9;
}

bool intersect(Point a, Point b, Point c, Point d) {
    double cp1 = cross_product(a, b, c);
    double cp2 = cross_product(a, b, d);
    double cp3 = cross_product(c, d, a);
    double cp4 = cross_product(c, d, b);

    if (((cp1 > 1e-9 && cp2 < -1e-9) || (cp1 < -1e-9 && cp2 > 1e-9)) &&
        ((cp3 > 1e-9 && cp4 < -1e-9) || (cp3 < -1e-9 && cp4 > 1e-9))) return true;

    if (onSegment(c, a, b) && !isSame(c, a) && !isSame(c, b)) return true;
    if (onSegment(d, a, b) && !isSame(d, a) && !isSame(d, b)) return true;

    return false;
}

bool isVisible(Point a, Point b, int M, const vector<Mural>& murals) {
    if (isSame(a, b)) return true;
    for (int i = 0; i < M; ++i) {
        if (intersect(a, b, murals[i].p1, murals[i].p2)) return false;
    }
    return true;
}

struct State {
    int u, t;
    double d;
    bool operator>(const State& other) const {
        return d > other.d;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T, M, C;
    while (cin >> T >> M >> C && (T != -1 || M != -1 || C != -1)) {
        vector<Mural> murals(M);
        for (int i = 0; i < M; ++i) {
            cin >> murals[i].p1.x >> murals[i].p1.y >> murals[i].p2.x >> murals[i].p2.y;
        }
        vector<Point> cabins(C);
        for (int i = 0; i < C; ++i) {
            cin >> cabins[i].x >> cabins[i].y;
        }
        Point start, portal;
        cin >> start.x >> start.y >> portal.x >> portal.y;

        vector<Point> pts;
        pts.push_back(start);  // Index 0
        pts.push_back(portal); // Index 1
        for (int i = 0; i < C; ++i) pts.push_back(cabins[i]); // 2 to C+1
        for (int i = 0; i < M; ++i) {
            pts.push_back(murals[i].p1);
            pts.push_back(murals[i].p2);
        }

        int n = pts.size();
        vector<vector<bool>> adj(n, vector<bool>(n));
        for (int i = 0; i < n; ++i) {
            for (int j = i; j < n; ++j) {
                adj[i][j] = adj[j][i] = isVisible(pts[i], pts[j], M, murals);
            }
        }

        vector<vector<double>> d(n, vector<double>(T + 1, 1e18));
        priority_queue<State, vector<State>, greater<State>> pq;

        d[0][0] = 0.0;
        pq.push({0, 0, 0.0});

        while (!pq.empty()) {
            State curr = pq.top();
            pq.pop();

            if (curr.d > d[curr.u][curr.t]) continue;

            // Transition 1: Walking
            for (int v = 0; v < n; ++v) {
                if (adj[curr.u][v]) {
                    double weight = dist(pts[curr.u], pts[v]);
                    if (d[v][curr.t] > curr.d + weight) {
                        d[v][curr.t] = curr.d + weight;
                        pq.push({v, curr.t, d[v][curr.t]});
                    }
                }
            }

            // Transition 2: Teleporting (Only between cabins)
            if (curr.u >= 2 && curr.u < C + 2 && curr.t < T) {
                for (int v = 2; v < C + 2; ++v) {
                    if (adj[curr.u][v]) {
                        if (d[v][curr.t + 1] > curr.d) {
                            d[v][curr.t + 1] = curr.d;
                            pq.push({v, curr.t + 1, d[v][curr.t + 1]});
                        }
                    }
                }
            }
        }

        double min_dist = 1e18;
        for (int t = 0; t <= T; ++t) {
            min_dist = min(min_dist, d[1][t]);
        }

        cout << fixed << setprecision(1) << min_dist << endl;
    }

    return 0;
}
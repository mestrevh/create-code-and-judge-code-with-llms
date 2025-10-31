/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
#include <queue>
#include <limits>
#include <algorithm>

struct Point {
    long long x, y;

    bool operator==(const Point& other) const {
        return x == other.x && y == other.y;
    }
    bool operator!=(const Point& other) const {
        return !(*this == other);
    }
};

const double INF = std::numeric_limits<double>::max();

double dist(Point p1, Point p2) {
    long long dx = p1.x - p2.x;
    long long dy = p1.y - p2.y;
    return std::sqrt(static_cast<double>(dx * dx + dy * dy));
}

long long cross_product(Point a, Point b, Point c) {
    return (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
}

bool on_segment(Point p, Point q, Point r) {
    return (q.x <= std::max(p.x, r.x) && q.x >= std::min(p.x, r.x) &&
            q.y <= std::max(p.y, r.y) && q.y >= std::min(p.y, r.y));
}

bool is_blocked(Point a, Point b, Point c, Point d) {
    if ((a == c && b == d) || (a == d && b == c)) {
        return false;
    }

    long long o1 = cross_product(a, b, c);
    long long o2 = cross_product(a, b, d);
    long long o3 = cross_product(c, d, a);
    long long o4 = cross_product(c, d, b);

    if (((o1 > 0 && o2 < 0) || (o1 < 0 && o2 > 0)) &&
        ((o3 > 0 && o4 < 0) || (o3 < 0 && o4 > 0))) {
        return true;
    }
    
    if (o1 == 0 && on_segment(a, c, b) && c != a && c != b) return true;
    if (o2 == 0 && on_segment(a, d, b) && d != a && d != b) return true;
    if (o3 == 0 && on_segment(c, a, d) && a != c && a != d) return true;
    if (o4 == 0 && on_segment(c, b, d) && b != c && b != d) return true;

    return false;
}

void solve() {
    int xi, yi, xf, yf, n;
    while (std::cin >> xi >> yi >> xf >> yf >> n && (xi || yi || xf || yf || n)) {
        std::vector<Point> nodes;
        nodes.push_back({(long long)xi, (long long)yi});
        nodes.push_back({(long long)xf, (long long)yf});

        std::vector<std::pair<Point, Point>> obstacles(n);
        for (int i = 0; i < n; ++i) {
            int x1, y1, x2, y2;
            std::cin >> x1 >> y1 >> x2 >> y2;
            obstacles[i] = {{(long long)x1, (long long)y1}, {(long long)x2, (long long)y2}};
            nodes.push_back(obstacles[i].first);
            nodes.push_back(obstacles[i].second);
        }

        int num_nodes = nodes.size();
        std::vector<std::vector<double>> adj(num_nodes, std::vector<double>(num_nodes, INF));

        for (int i = 0; i < num_nodes; ++i) {
            for (int j = i; j < num_nodes; ++j) {
                if (i == j) {
                    adj[i][j] = 0;
                    continue;
                }

                Point p1 = nodes[i];
                Point p2 = nodes[j];
                
                bool obstructed = false;
                for (int k = 0; k < n; ++k) {
                    if (is_blocked(p1, p2, obstacles[k].first, obstacles[k].second)) {
                        obstructed = true;
                        break;
                    }
                }

                if (!obstructed) {
                    double d = dist(p1, p2);
                    adj[i][j] = d;
                    adj[j][i] = d;
                }
            }
        }
        
        std::vector<double> min_dist(num_nodes, INF);
        min_dist[0] = 0;
        std::priority_queue<std::pair<double, int>, std::vector<std::pair<double, int>>, std::greater<std::pair<double, int>>> pq;
        pq.push({0.0, 0});

        while (!pq.empty()) {
            double d = pq.top().first;
            int u = pq.top().second;
            pq.pop();

            if (d > min_dist[u]) {
                continue;
            }
            if (u == 1) {
                break;
            }

            for (int v = 0; v < num_nodes; ++v) {
                if (adj[u][v] != INF) {
                    if (min_dist[u] + adj[u][v] < min_dist[v]) {
                        min_dist[v] = min_dist[u] + adj[u][v];
                        pq.push({min_dist[v], v});
                    }
                }
            }
        }

        std::cout << std::fixed << std::setprecision(2) << min_dist[1] << std::endl;
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    solve();
    return 0;
}

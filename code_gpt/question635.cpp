/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <cmath>
#include <limits>
#include <iomanip>
#include <queue>
#include <utility>

using namespace std;

struct Point {
    double x, y;
};

struct Edge {
    int to;
    double cost;
};

double distance(Point a, Point b) {
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

bool intersects(Point a, Point b, Point c, Point d) {
    double cross1 = (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
    double cross2 = (b.x - a.x) * (d.y - a.y) - (b.y - a.y) * (d.x - a.x);
    double cross3 = (d.x - c.x) * (a.y - c.y) - (d.y - c.y) * (a.x - c.x);
    double cross4 = (d.x - c.x) * (b.y - c.y) - (d.y - c.y) * (b.x - c.x);
    return (cross1 * cross2 < 0) && (cross3 * cross4 < 0);
}

bool isValid(Point start, Point end, const vector<pair<Point, Point>>& obstacles) {
    for (auto& obs : obstacles) {
        if (intersects(start, end, obs.first, obs.second)) {
            return false;
        }
    }
    return true;
}

double dijkstra(Point start, Point end, const vector<pair<Point, Point>>& obstacles) {
    priority_queue<pair<double, Point>, vector<pair<double, Point>>, greater<pair<double, Point>>> pq;
    pq.push({0, start});
    
    set<Point> visited;
    double min_distance = numeric_limits<double>::max();

    while (!pq.empty()) {
        auto [cur_dist, cur_point] = pq.top();
        pq.pop();

        if (visited.count(cur_point)) continue;
        visited.insert(cur_point);

        if (cur_point.x == end.x && cur_point.y == end.y) {
            min_distance = min(min_distance, cur_dist);
            continue;
        }

        for (double x = -5000; x <= 5000; x += 1) {
            for (double y = -5000; y <= 5000; y += 1) {
                Point next_point = {x, y};
                if (isValid(cur_point, next_point, obstacles)) {
                    double new_dist = cur_dist + distance(cur_point, next_point);
                    pq.push({new_dist, next_point});
                }
            }
        }
    }
    return min_distance;
}

int main() {
    int xi, yi, xf, yf, n;

    while (true) {
        cin >> xi >> yi >> xf >> yf >> n;
        if (xi == 0 && yi == 0 && xf == 0 && yf == 0 && n == 0) break;

        Point start = {static_cast<double>(xi), static_cast<double>(yi)};
        Point end = {static_cast<double>(xf), static_cast<double>(yf)};
        vector<pair<Point, Point>> obstacles(n);

        for (int i = 0; i < n; ++i) {
            int x1, y1, x2, y2;
            cin >> x1 >> y1 >> x2 >> y2;
            obstacles[i] = {{static_cast<double>(x1), static_cast<double>(y1)}, {static_cast<double>(x2), static_cast<double>(y2)}};
        }

        double result = dijkstra(start, end, obstacles);
        cout << fixed << setprecision(2) << result << endl;
    }
    return 0;
}

/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

struct Point {
    double x, y;
    bool operator==(const Point &p) const {
        return x == p.x && y == p.y;
    }
};

struct Wall {
    Point a, b;
};

double distance(const Point &p1, const Point &p2) {
    return sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
}

bool intersects(const Wall &w, const Point &p) {
    double cross = (w.b.x - w.a.x) * (p.y - w.a.y) - (w.b.y - w.a.y) * (p.x - w.a.x);
    return abs(cross) < 1e-9;
}

bool canTeleport(const Point &src, const Point &dst, const vector<Wall> &walls) {
    for (const auto &w : walls) {
        if (intersects(w, src) || intersects(w, dst)) return false;
        // Check if line between src and dst intersects wall
        double wallOrientation = (w.b.x - w.a.x) * (src.y - w.a.y) - (w.b.y - w.a.y) * (src.x - w.a.x);
        double lineOrientation = (w.b.x - w.a.x) * (dst.y - w.a.y) - (w.b.y - w.a.y) * (dst.x - w.a.x);
        if (wallOrientation * lineOrientation < 0) return false;
    }
    return true;
}

double dijkstra(const Point &start, const Point &end, const vector<Point> &teleporters, const vector<Wall> &walls, int t) {
    priority_queue<pair<double, Point>, vector<pair<double, Point>>, greater<pair<double, Point>>> pq;
    map<Point, double> dist;
    pq.push({0, start});
    dist[start] = 0;

    while (!pq.empty()) {
        auto [curDist, curPos] = pq.top();
        pq.pop();

        if (curPos == end) return curDist;

        if (curDist > dist[curPos]) continue;

        for (const auto &teleporter : teleporters) {
            if (canTeleport(curPos, teleporter, walls)) {
                double newDist = curDist;
                if (t > 0) newDist += distance(curPos, teleporter);
                if (dist.find(teleporter) == dist.end() || newDist < dist[teleporter]) {
                    dist[teleporter] = newDist;
                    pq.push({newDist, teleporter});
                }
            }
        }
        for (const auto &teleporter : teleporters) {
            if (canTeleport(curPos, end, walls)) {
                double newDist = curDist + distance(curPos, end);
                if (dist.find(end) == dist.end() || newDist < dist[end]) {
                    dist[end] = newDist;
                    pq.push({newDist, end});
                }
            }
        }
    }
    return -1; // in case no path found
}

int main() {
    int T, M, C;
    while (cin >> T >> M >> C, T != -1) {
        vector<Wall> walls(M);
        for (int i = 0; i < M; ++i) {
            cin >> walls[i].a.x >> walls[i].a.y >> walls[i].b.x >> walls[i].b.y;
        }
        
        vector<Point> teleporters(C);
        for (int i = 0; i < C; ++i) {
            cin >> teleporters[i].x >> teleporters[i].y;
        }

        Point start, end;
        cin >> start.x >> start.y >> end.x >> end.y;

        double result = dijkstra(start, end, teleporters, walls, T);
        if (result != -1) {
            cout << fixed << setprecision(1) << result << endl;
        } else {
            cout << "NO PATH" << endl;
        }
    }
    return 0;
}

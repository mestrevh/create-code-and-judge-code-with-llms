/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

struct Point {
    long long x, y;
};

static inline long long cross(const Point& O, const Point& A, const Point& B) {
    return (A.x - O.x) * (B.y - O.y) - (A.y - O.y) * (B.x - O.x);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int C;
    if (!(cin >> C)) return 0;

    for (int tc = 0; tc < C; tc++) {
        int N;
        cin >> N;
        vector<Point> p(N);
        for (int i = 0; i < N; i++) cin >> p[i].x >> p[i].y;

        if (N == 0) {
            cout << "caso " << tc << ":\n\n";
            continue;
        }
        if (N == 1) {
            cout << "caso " << tc << ":\n" << p[0].x << " " << p[0].y << "\n\n";
            continue;
        }
        if (N == 2) {
            int a = 0, b = 1;
            if (p[b].y < p[a].y || (p[b].y == p[a].y && p[b].x < p[a].x)) swap(a, b);
            vector<int> idx = {a, b};
            cout << "caso " << tc << ":\n";
            cout << p[idx[0]].x << " " << p[idx[0]].y << "\n";
            cout << p[idx[1]].x << " " << p[idx[1]].y << "\n\n";
            continue;
        }

        vector<Point> pts = p;
        sort(pts.begin(), pts.end(), [](const Point& a, const Point& b){
            if (a.x != b.x) return a.x < b.x;
            return a.y < b.y;
        });
        pts.erase(unique(pts.begin(), pts.end(), [](const Point& a, const Point& b){
            return a.x == b.x && a.y == b.y;
        }), pts.end());

        if (pts.size() == 1) {
            cout << "caso " << tc << ":\n" << pts[0].x << " " << pts[0].y << "\n\n";
            continue;
        }
        if (pts.size() == 2) {
            Point a = pts[0], b = pts[1];
            if (b.y < a.y || (b.y == a.y && b.x < a.x)) swap(a,b);
            cout << "caso " << tc << ":\n" << a.x << " " << a.y << "\n" << b.x << " " << b.y << "\n\n";
            continue;
        }

        vector<Point> lower, upper;
        for (auto &pt : pts) {
            while (lower.size() >= 2 && cross(lower[lower.size()-2], lower[lower.size()-1], pt) < 0) lower.pop_back();
            lower.push_back(pt);
        }
        for (int i = (int)pts.size() - 1; i >= 0; i--) {
            auto &pt = pts[i];
            while (upper.size() >= 2 && cross(upper[upper.size()-2], upper[upper.size()-1], pt) < 0) upper.pop_back();
            upper.push_back(pt);
        }

        vector<Point> hull = lower;
        hull.pop_back();
        hull.insert(hull.end(), upper.begin(), upper.end());
        if (hull.size() == 2) {
            Point a = hull[0], b = hull[1];
            if (b.y < a.y || (b.y == a.y && b.x < a.x)) swap(a,b);
            cout << "caso " << tc << ":\n" << a.x << " " << a.y << "\n" << b.x << " " << b.y << "\n\n";
            continue;
        }

        int m = (int)hull.size();
        int start = 0;
        for (int i = 1; i < m; i++) {
            if (hull[i].y < hull[start].y || (hull[i].y == hull[start].y && hull[i].x < hull[start].x))
                start = i;
        }

        vector<Point> rotated(m);
        for (int i = 0; i < m; i++) rotated[i] = hull[(start + i) % m];

        bool needFlip = false;
        if (m >= 3) {
            long long area2 = 0;
            for (int i = 0; i < m; i++) {
                int j = (i + 1) % m;
                area2 += rotated[i].x * rotated[j].y - rotated[i].y * rotated[j].x;
            }
            if (area2 < 0) needFlip = true;
        }
        if (needFlip && m >= 3) {
            vector<Point> rev(m);
            rev[0] = rotated[0];
            for (int i = 1; i < m; i++) rev[i] = rotated[m - i];
            rotated.swap(rev);
        }

        cout << "caso " << tc << ":\n";
        for (int i = 0; i < m; i++) {
            cout << rotated[i].x << " " << rotated[i].y << "\n";
        }
        cout << "\n";
    }

    return 0;
}
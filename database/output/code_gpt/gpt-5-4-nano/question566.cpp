/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

struct Point {
    double x, y;
};

static inline double dist2(const Point& a, const Point& b) {
    double dx = a.x - b.x;
    double dy = a.y - b.y;
    return dx*dx + dy*dy;
}

static inline double distd(const Point& a, const Point& b) {
    return sqrt(dist2(a,b));
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    const double INF_LIMIT = 10000.0;
    const double INF2_LIMIT = INF_LIMIT * INF_LIMIT;
    while ( (cin >> N) ) {
        if (N == 0) break;
        vector<Point> pts(N);
        for (int i = 0; i < N; i++) {
            cin >> pts[i].x >> pts[i].y;
        }

        sort(pts.begin(), pts.end(), [](const Point& a, const Point& b){
            if (a.x != b.x) return a.x < b.x;
            return a.y < b.y;
        });

        vector<Point> tmp(N);

        function<double(int,int)> solve = [&](int l, int r) -> double {
            int n = r - l;
            if (n <= 3) {
                double best = numeric_limits<double>::infinity();
                for (int i = l; i < r; i++)
                    for (int j = i + 1; j < r; j++)
                        best = min(best, dist2(pts[i], pts[j]));
                sort(pts.begin() + l, pts.begin() + r, [](const Point& a, const Point& b){
                    if (a.y != b.y) return a.y < b.y;
                    return a.x < b.x;
                });
                return best;
            }

            int m = (l + r) / 2;
            double midx = pts[m].x;

            double dl = solve(l, m);
            double dr = solve(m, r);
            double d = min(dl, dr);

            merge(pts.begin() + l, pts.begin() + m,
                  pts.begin() + m, pts.begin() + r,
                  tmp.begin(),
                  [](const Point& a, const Point& b){
                      if (a.y != b.y) return a.y < b.y;
                      return a.x < b.x;
                  });
            copy(tmp.begin(), tmp.begin() + (r - l), pts.begin() + l);

            double limit = d;
            vector<Point> strip;
            strip.reserve(r - l);

            for (int i = l; i < r; i++) {
                double dx = pts[i].x - midx;
                if (dx*dx < limit) strip.push_back(pts[i]);
            }

            for (size_t i = 0; i < strip.size(); i++) {
                for (size_t j = i + 1; j < strip.size(); j++) {
                    double dy = strip[j].y - strip[i].y;
                    if (dy*dy >= limit) break;
                    limit = min(limit, dist2(strip[i], strip[j]));
                }
            }
            return limit;
        };

        double best2;
        if (N < 2) {
            best2 = numeric_limits<double>::infinity();
        } else {
            best2 = solve(0, N);
        }

        if (!(best2 < INF2_LIMIT)) {
            cout << "INFINITY\n";
        } else {
            cout.setf(std::ios::fixed); 
            cout << setprecision(4) << sqrt(best2) << "\n";
        }
    }
    return 0;
}
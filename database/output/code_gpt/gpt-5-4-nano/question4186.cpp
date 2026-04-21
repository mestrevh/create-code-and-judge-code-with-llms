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

static inline double dist(const Point& a, const Point& b) {
    return sqrt(dist2(a,b));
}

double closestPair(vector<Point>& pts) {
    int n = (int)pts.size();
    sort(pts.begin(), pts.end(), [](const Point& a, const Point& b){
        if (a.x != b.x) return a.x < b.x;
        return a.y < b.y;
    });

    vector<Point> temp(n);

    function<double(int,int)> solve = [&](int l, int r)->double {
        int m = (l + r) / 2;
        double midx = pts[m].x;

        double d = min(solve(l, m), solve(m, r));

        merge(pts.begin()+l, pts.begin()+m, pts.begin()+m, pts.begin()+r, temp.begin(),
              [](const Point& a, const Point& b){
                  if (a.y != b.y) return a.y < b.y;
                  return a.x < b.x;
              });
        copy(temp.begin(), temp.begin() + (r - l), pts.begin() + l);

        vector<Point> strip;
        strip.reserve(r - l);
        for (int i = l; i < r; i++) {
            double dx = pts[i].x - midx;
            if (dx*dx < d) strip.push_back(pts[i]);
        }

        for (int i = 0; i < (int)strip.size(); i++) {
            for (int j = i + 1; j < (int)strip.size(); j++) {
                double dy = strip[j].y - strip[i].y;
                if (dy*dy >= d) break;
                d = min(d, dist2(strip[i], strip[j]));
            }
        }
        return d;
    };

    double ans2;
    if (n < 2) ans2 = 0.0;
    else ans2 = solve(0, n);

    return sqrt(ans2);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    if (!(cin >> n)) return 0;
    vector<Point> pts(n);
    for (int i = 0; i < n; i++) {
        int xi, yi;
        cin >> xi >> yi;
        pts[i] = Point{(double)xi, (double)yi};
    }

    double ans = closestPair(pts);
    cout.setf(std::ios::fixed);
    cout << setprecision(4) << ans << "\n";
    return 0;
}
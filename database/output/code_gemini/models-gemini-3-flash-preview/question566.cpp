/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <set>

using namespace std;

struct Point {
    double x, y;
};

bool compareX(const Point& a, const Point& b) {
    if (a.x != b.x) return a.x < b.x;
    return a.y < b.y;
}

struct compareY {
    bool operator()(const Point& a, const Point& b) const {
        if (a.y != b.y) return a.y < b.y;
        return a.x < b.x;
    }
};

inline double distSq(const Point& a, const Point& b) {
    return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    while (cin >> n && n != 0) {
        vector<Point> pts(n);
        for (int i = 0; i < n; ++i) {
            cin >> pts[i].x >> pts[i].y;
        }

        if (n < 2) {
            cout << "INFINITY" << endl;
            continue;
        }

        sort(pts.begin(), pts.end(), compareX);

        multiset<Point, compareY> s;
        double d = 10000.0;
        double d_sq = 100000000.0;
        int left = 0;

        for (int i = 0; i < n; ++i) {
            while (left < i && pts[i].x - pts[left].x >= d) {
                auto it_erase = s.find(pts[left]);
                if (it_erase != s.end()) {
                    s.erase(it_erase);
                }
                left++;
            }

            auto it_low = s.lower_bound({-1e9, pts[i].y - d});
            auto it_up = s.upper_bound({1e9, pts[i].y + d});

            for (auto it = it_low; it != it_up; ++it) {
                double ds = distSq(pts[i], *it);
                if (ds < d_sq) {
                    d_sq = ds;
                    d = sqrt(d_sq);
                }
            }
            s.insert(pts[i]);
        }

        if (d >= 10000.0) {
            cout << "INFINITY" << endl;
        } else {
            cout << fixed << setprecision(4) << d << endl;
        }
    }

    return 0;
}
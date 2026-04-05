/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

struct Point {
    double x, y;
};

static const double EPS = 1e-12;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    if (!(cin >> n)) return 0;
    vector<Point> pts(n);
    for (int i = 0; i < n; i++) cin >> pts[i].x >> pts[i].y;

    set<pair<double,double>> extremeSet;

    auto cross = [&](const Point& a, const Point& b, const Point& c) -> long double {
        long double abx = (long double)b.x - a.x;
        long double aby = (long double)b.y - a.y;
        long double acx = (long double)c.x - a.x;
        long double acy = (long double)c.y - a.y;
        return abx * acy - aby * acx;
    };

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            bool allSame = true;
            int pos = 0, neg = 0;
            for (int k = 0; k < n; k++) {
                if (k == i || k == j) continue;
                long double cr = cross(pts[i], pts[j], pts[k]);
                if (fabsl(cr) <= (long double)EPS) continue;
                if (cr > 0) pos++;
                else neg++;
                if (pos > 0 && neg > 0) { allSame = false; break; }
            }
            if (allSame && (pos > 0 || neg > 0 || true)) {
                long double crAny = 0;
                extremeSet.insert({pts[i].x, pts[i].y});
                extremeSet.insert({pts[j].x, pts[j].y});
            }
        }
    }

    vector<pair<double,double>> extremes;
    extremes.reserve(extremeSet.size());
    for (auto &p : extremeSet) extremes.push_back(p);

    sort(extremes.begin(), extremes.end(), [](const auto& a, const auto& b){
        if (a.first != b.first) return a.first < b.first;
        return a.second < b.second;
    });

    cout.setf(std::ios::fixed); 
    cout << setprecision(4);

    for (auto &p : extremes) {
        cout << p.first + 0.0 << " " << p.second + 0.0 << "\n";
    }
    return 0;
}
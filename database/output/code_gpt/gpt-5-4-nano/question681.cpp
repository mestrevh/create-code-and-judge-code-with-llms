/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

struct Point {
    double x, y;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int C;
    if (!(cin >> C)) return 0;
    cout.setf(std::ios::fixed);
    cout << setprecision(2);

    for (int tc = 0; tc < C; tc++) {
        int N;
        cin >> N;
        vector<pair<int,int>> pts(N);
        for (int i = 0; i < N; i++) {
            int x, y;
            cin >> x >> y;
            pts[i] = {x, y};
        }

        sort(pts.begin(), pts.end(), [](const auto& a, const auto& b){
            return a.first < b.first;
        });

        vector<Point> p(N);
        for (int i = 0; i < N; i++) p[i] = {(double)pts[i].first, (double)pts[i].second};

        auto dist = [&](const Point& a, const Point& b)->double{
            double dx = a.x - b.x;
            double dy = a.y - b.y;
            return sqrt(dx*dx + dy*dy);
        };

        double total = 0.0;

        for (int i = 0; i + 1 < N; i++) {
            bool leftPeak = (i == 0) ? true : (p[i].y >= p[i-1].y);
            bool rightPeak = (i+1 == N-1) ? true : (p[i+1].y >= p[i+2].y);
            bool becomesRed = false;

            if (i > 0) {
                becomesRed = becomesRed || (p[i].y > p[i-1].y);
            }
            if (i + 2 < N) {
                becomesRed = becomesRed || (p[i+1].y > p[i+2].y);
            }

            if (becomesRed) total += dist(p[i], p[i+1]);
        }

        cout << total + 0.0 << "\n";
    }
    return 0;
}
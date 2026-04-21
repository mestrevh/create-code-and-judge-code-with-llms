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
    double dx = a.x - b.x, dy = a.y - b.y;
    return dx*dx + dy*dy;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    while ( (cin >> N) ) {
        if (N == 0) break;
        vector<Point> p(N);
        for (int i = 0; i < N; i++) {
            long long xi, yi;
            cin >> xi >> yi;
            p[i] = { (double)xi, (double)yi };
        }

        vector<double> d(N*N);
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                d[i*N + j] = dist2(p[i], p[j]);
            }
        }
        sort(d.begin(), d.end());
        d.erase(unique(d.begin(), d.end(), [](double a, double b){
            return fabs(a-b) < 1e-12;
        }), d.end());

        int M = (int)d.size();
        double lo = 0.0;
        double hi = sqrt(d.back()) + 1.0;

        auto can = [&](double r) -> bool {
            double rr = r*r + 1e-9;
            vector<unsigned long long> cover(N, 0);
            int K = (N <= 64 ? N : 0);
            if (K == 0) return false;

            for (int i = 0; i < N; i++) {
                unsigned long long mask = 0;
                for (int j = 0; j < N; j++) {
                    if (dist2(p[i], p[j]) <= rr) mask |= (1ULL << j);
                }
                cover[i] = mask;
            }

            unsigned long long full = (N == 64 ? ~0ULL : ((1ULL << N) - 1ULL));
            for (int i = 0; i < N; i++) {
                if (cover[i] == full) return true;
                for (int j = i; j < N; j++) {
                    if ( (cover[i] | cover[j]) == full ) return true;
                }
            }
            return false;
        };

        auto can2 = [&](double rr) -> bool {
            double r2 = rr + 1e-9;
            vector<unsigned long long> cover(N, 0);
            for (int i = 0; i < N; i++) {
                unsigned long long mask = 0;
                for (int j = 0; j < N; j++) {
                    if (dist2(p[i], p[j]) <= r2) mask |= (1ULL << j);
                }
                cover[i] = mask;
            }
            unsigned long long full = (N == 64 ? ~0ULL : ((1ULL << N) - 1ULL));
            for (int i = 0; i < N; i++) {
                for (int j = i; j < N; j++) {
                    if ((cover[i] | cover[j]) == full) return true;
                }
            }
            return false;
        };

        double ans2 = hi*hi;
        int lidx = 0, ridx = M - 1;
        while (lidx <= ridx) {
            int mid = (lidx + ridx) / 2;
            double rr = d[mid];
            if (can2(rr)) {
                ans2 = rr;
                ridx = mid - 1;
            } else {
                lidx = mid + 1;
            }
        }

        double ans = sqrt(ans2);
        cout.setf(std::ios::fixed); 
        cout << setprecision(2) << ans + 1e-9 << "\n";
    }
    return 0;
}
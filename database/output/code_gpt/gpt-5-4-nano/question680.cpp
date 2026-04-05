/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

struct Pt {
    double x, y;
};

static const double EPS = 1e-10;

double distPointSegment(const Pt& M, const Pt& A, const Pt& B, Pt& closest) {
    double vx = B.x - A.x, vy = B.y - A.y;
    double wx = M.x - A.x, wy = M.y - A.y;
    double vv = vx*vx + vy*vy;
    double t = 0.0;
    if (vv > EPS) t = (wx*vx + wy*vy) / vv;
    if (t < 0.0) t = 0.0;
    if (t > 1.0) t = 1.0;
    closest = {A.x + t*vx, A.y + t*vy};
    double dx = M.x - closest.x, dy = M.y - closest.y;
    return dx*dx + dy*dy;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    double Xm, Ym;
    while (true) {
        if (!(cin >> Xm)) break;
        if (!(cin >> Ym)) break;
        int N;
        cin >> N;

        vector<Pt> P;
        P.reserve(N + 1);
        for (int i = 0; i < N + 1; i++) {
            double x, y;
            cin >> x >> y;
            P.push_back({x, y});
        }

        Pt M{Xm, Ym};
        double bestD = numeric_limits<double>::infinity();
        Pt bestC{0, 0};

        for (int i = 0; i < N; i++) {
            Pt A = P[i], B = P[i+1], C;
            double d2 = distPointSegment(M, A, B, C);
            if (d2 < bestD - 1e-12) {
                bestD = d2;
                bestC = C;
            }
        }

        cout.setf(std::ios::fixed); 
        cout << setprecision(4) << bestC.x << "\n" << bestC.y << "\n";
    }
    return 0;
}
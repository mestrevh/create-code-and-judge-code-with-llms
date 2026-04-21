/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N;
    if (!(cin >> N)) return 0;
    while (N--) {
        long long x1, y1, x2, y2;
        long long x3, y3, x4, y4;
        long long x5, y5, x6, y6;
        cin >> x1 >> y1 >> x2 >> y2;
        cin >> x3 >> y3 >> x4 >> y4;
        cin >> x5 >> y5 >> x6 >> y6;

        long long ax = x2 - x1, ay = y2 - y1;
        long long bx = x4 - x3, by = y4 - y3;
        long long cx = x6 - x5, cy = y6 - y5;

        long long sx = x3 - x1, sy = y3 - y1;
        long long tx = x5 - x1, ty = y5 - y1;

        auto triArea2 = [&](long long px, long long py, long long qx, long long qy, long long rx, long long ry) -> long long {
            long long ux = qx - px, uy = qy - py;
            long long vx = rx - px, vy = ry - py;
            return llabs(ux * vy - uy * vx);
        };

        long long A = triArea2(x1, y1, x2, y2, x3, y3);
        long long B = triArea2(x1, y1, x2, y2, x4, y4);
        long long C = triArea2(x1, y1, x2, y2, x5, y5);
        long long D = triArea2(x1, y1, x2, y2, x6, y6);

        long long E = triArea2(x3, y3, x4, y4, x1, y1);
        long long F = triArea2(x3, y3, x4, y4, x2, y2);

        long long G = triArea2(x5, y5, x6, y6, x1, y1);
        long long H = triArea2(x5, y5, x6, y6, x2, y2);

        bool ok = false;
        long long p1x = x1, p1y = y1;
        long long p2x = x2, p2y = y2;
        long long q1x = x3, q1y = y3;
        long long q2x = x4, q2y = y4;
        long long r1x = x5, r1y = y5;
        long long r2x = x6, r2y = y6;

        vector<pair<long long,long long>> P = {{p1x,p1y},{p2x,p2y}};
        vector<pair<long long,long long>> Q = {{q1x,q1y},{q2x,q2y}};
        vector<pair<long long,long long>> R = {{r1x,r1y},{r2x,r2y}};

        for (auto &pp : P) {
            for (auto &qq : Q) {
                for (auto &rr : R) {
                    if (triArea2(pp.first, pp.second, qq.first, qq.second, rr.first, rr.second) != 0) {
                        ok = true;
                        break;
                    }
                }
                if (ok) break;
            }
            if (ok) break;
        }

        cout << (ok ? "SIM" : "NAO") << "\n";
    }
    return 0;
}
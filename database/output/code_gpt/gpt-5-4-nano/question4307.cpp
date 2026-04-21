/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

static int quadrant(long long x, long long y) {
    if (x == 0 || y == 0) return 0;
    if (x > 0 && y > 0) return 1;
    if (x < 0 && y > 0) return 2;
    if (x < 0 && y < 0) return 3;
    return 4;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long x, y;
    long long c;
    if (!(cin >> x >> y >> c)) return 0;

    long long xt = 1, yt = 1;

    if (c == 1 && xt > 0 && yt > 0 && quadrant(x,y) == 1) {}

    int qStart = quadrant(x, y);
    int qDest = quadrant(xt, yt);

    if (qDest == 0) {
        cout << "caminhada invalida\n";
        return 0;
    }

    bool ok = false;
    pair<long long,long long> ans;

    long long ax = llabs(xt - x);
    long long ay = llabs(yt - y);

    auto isInvalidPath = [&](bool yFirst) -> bool {
        long long cx = x, cy = y;

        if (yFirst) {
            long long stepY = (yt > cy) ? 1 : -1;
            for (long long i = 0; i < ay; i++) {
                long long ny = cy + stepY;
                long long q = quadrant(cx, ny);
                if (q == (int)c) return true;
                cy = ny;
            }
            long long stepX = (xt > cx) ? 1 : -1;
            for (long long i = 0; i < ax; i++) {
                long long nx = cx + stepX;
                long long q = quadrant(nx, cy);
                if (q == (int)c) return true;
                cx = nx;
            }
        } else {
            long long stepX = (xt > cx) ? 1 : -1;
            for (long long i = 0; i < ax; i++) {
                long long nx = cx + stepX;
                long long q = quadrant(nx, cy);
                if (q == (int)c) return true;
                cx = nx;
            }
            long long stepY = (yt > cy) ? 1 : -1;
            for (long long i = 0; i < ay; i++) {
                long long ny = cy + stepY;
                long long q = quadrant(cx, ny);
                if (q == (int)c) return true;
                cy = ny;
            }
        }
        return false;
    };

    if (!isInvalidPath(true)) {
        ok = true;
        ans = {ax, ay};
        cout << ay << " passos em y e " << ax << " passos em x\n";
        return 0;
    }
    if (!isInvalidPath(false)) {
        ok = true;
        ans = {ax, ay};
        cout << ax << " passos em y e " << ay << " passos em x\n";
        return 0;
    }

    cout << "caminhada invalida\n";
    return 0;
}